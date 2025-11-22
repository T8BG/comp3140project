#include <vector>
#include <iostream>
using namespace std;

#include "../headers/Admin.h"
#include "../headers/Customer.h"
#include "../headers/Repository/AccountRepository.h"
#include "../headers/ServiceClass/AccountServices.h"
#include "../headers/ServiceClass/AuthenticationService.h"

int main() {
    // Create repository and servidce objects
    AccountRepository accountRepository;
    AccountService accountService(accountRepository);
    AuthenticationService authService;
    
    // All new customers will start with no accounts (an empty list)
    std::vector<int> initialAccounts;

    // Create a new customer object
    Customer customer("T001","John Doe","randompassword","123 Kamloops Ave",
        "123-456-6788","test@gmail.com",initialAccounts);

    // Create a new admin object
    Admin admin("Admin1", "001", accountService);

    // Admin then creates an account for the customer
    admin.createAccount(customer);

    std::cout << "All accounts: " << std::endl;
    admin.viewAllAccounts();
    std::cout << std::endl << "=== Admin Login ===" << std::endl;
    bool loginResult = authService.authenticateAdmin(admin);
    cout << "Admin login result: " << loginResult << endl;
    
    return 0;
}
