#include <vector>
#include <iostream>
using namespace std;

#include "../headers/Admin.h"
#include "../headers/Customer.h"
#include "../headers/Repository/AccountRepository.h"
#include "../headers/Repository/TransactionRepository.h"
#include "../headers/ServiceClass/AccountServices.h"
#include "../headers/ServiceClass/AuthenticationService.h"
#include "../headers/ServiceClass/TransferService.h"

int main() {
    // Create repository and servidce objects
    AccountRepository accountRepository;
    TransactionRepository transactionRepository;
    AccountService accountService(accountRepository);
    AuthenticationService authService;
    TransferService transferService(transactionRepository, accountRepository);
    
    // All new customers will start with no accounts (an empty list)
    std::vector<int> initialAccounts;

    // Create a new customer object
    Customer customer("T001","John Doe","randompassword","123 Kamloops Ave",
        "123-456-6788","test@gmail.com",initialAccounts);

    Customer customer2("T002","John Wick","randompassword","123 Kamloops Ave",
            "123-456-6788","test@gmail.com",initialAccounts);

    // Create a new admin object
    Admin admin("Admin1", "password", accountService);

    // Admin then creates an account for the customer
    admin.createAccount(customer);
    admin.createAccount(customer2);
    std::cout << std::endl;
    
    // print all accounts
    std::cout << "All accounts: " << std::endl;
    admin.viewAllAccounts();
    std::cout << std::endl;

    int testAccount1 = 1000;
    // deposit $500
    transferService.deposit(testAccount1, 500.0);
    
    // withdraw $300
    transferService.withdraw(testAccount1, 300.0);
    
    std::cout << std::endl << "accounts after withdrawal: " << std::endl;
    admin.viewAllAccounts();
    std::cout << std::endl;
    
    // transfer $200 from account 1000 to account 1001
    transferService.transfer(testAccount1, 1001, 200.0);
    
    // Testing view all transactions for account
    std::cout << std::endl << "View all tansactions for account" << std::endl;
    transferService.transactionHistory(testAccount1);

    // Admin login
    std::cout << std::endl << "=== Admin Login ===" << std::endl;
    bool loginResult = authService.authenticateAdmin(admin);
    cout << "Admin login result: " << loginResult << endl;

    // Testing delete account
    std::cout << std::endl << "=== Testing Delete Account ===" << std::endl;
    std::cout << "Attempting to delete account 1000..." << std::endl;
    admin.deleteAccount(1000);
    
    std::cout << std::endl << "All accounts after deletion: " << std::endl;
    admin.viewAllAccounts();
    


    return 0;
}
