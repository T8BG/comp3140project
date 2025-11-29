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

    // Variables for menu
    int acctType;
    int menuSelect;
    
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

    // Testing delete account
    std::cout << std::endl << "=== Testing Delete Account ===" << std::endl;
    std::cout << "Attempting to delete account 1000..." << std::endl;
    admin.deleteAccount(1000);
    
    std::cout << std::endl << "All accounts after deletion: " << std::endl;
    admin.viewAllAccounts();
    
    //MAIN MENU PROMPTING
    while(true)
    {
        // Select type of account
        while(true)
        {
            cout << "What account type would you like to log into?";
            cout << "1. Admin";
            cout << "2. Customer";
            cout << "3. Register";
            cin >> acctType;
            if(acctType == 1 || acctType == 2)
            {
                break;
            }
            else
            {
                cout << "Please enter either a '1' or a '2'";
            }
        }
        
        // Log in
        while(true)
        {
            if(acctType == 1)
            {
                // Admin login
                std::cout << std::endl << "=== Admin Login ===" << std::endl;
                bool loginResult = authService.authenticateAdmin(admin);
                if(loginResult == true)
                {
                    break;
                }
                else
                {
                    cout << "Either the username or password is incorrect.";
                }
            }
            else if(acctType == 2)
            {
                std::cout << std::endl << "=== Customer Login ===" << std::endl;
                bool loginResult = authService.authenticateCustomer(customer);
                if(loginResult == true)
                {
                    break;
                }
                else
                {
                    cout << "Either the username or password is incorrect.";
                }

            }
        }

        //Main menu
        cout << "Please enter your selection.";

        // Admin selection
        if(acctType == 1)
        {
            cout << "1. Create User Account";
            cout << "2. Delete User Account";
            cout << "3. View Accounts";
            cout << "4. Log out";
            cout << "9. Exit Program";
        }

        // Customer selection
        if(acctType == 2)
        {
            cout << "1. Deposit funds";
            cout << "2. Withdraw funds";
            cout << "3. Transfer funds";
            cout << "4. View Transaction History";
            cout << "5. Log out";
            cout << "9. Exit Program";
        }
        while(true)
        {
            cin >> menuSelect;

            //Has to be if-else statements in order to break properly.
            if(menuSelect == 1)
            {

            }
            else if(menuSelect == 2)
            {
                
            }
            else if(menuSelect == 3)
            {
                
            }
            else if(menuSelect == 4)
            {
                if(acctType == 1)
                {
                    break;
                }
                else
                {
                    
                }
            }
            else if(menuSelect == 5)
            {
                if(acctType == 1)
                {
                    cout << "Please select a valid menu item.";
                }
                else
                {
                    break;
                }
            }
            else if(menuSelect == 9)
            {
                exit(0);
            }
            else
            {

            }
        }

    }

    return 0;
}
