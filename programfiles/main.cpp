#include <vector>
#include <iostream>
using namespace std;

#include "../headers/Admin.h"
#include "../headers/Customer.h"
#include "../headers/Repository/AccountRepository.h"
#include "../headers/ServiceClass/AccountServices.h"
#include "../headers/ServiceClass/AuthenticationService.h"

int main() {
    //TESTING FOR STAGE 4
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

    //DEFINE VARIABLES
    int Acctnumber;
    string username;
    string password;

    int input;
    
    //USER SELECTS WHICH ACCOUNT THEY WANT TO ACCESS
    cout << "Which type of account do you request?";
    cout << "1. Customer";
    cout << "2. Admin";
    while(true)
    {
        cin >> Acctnumber;
        switch (Acctnumber)
        {
            case 1:
            break;

            case 2:
            break;

            default:
            cout << "Please enter a '1' or a '2'";
        }
    }

    //USER ENTERS THEIR USERNAME AND PASSWORD
    cout << "Please enter your username";
    cin >> username;
    cout << "Please enter your password";
    cin >> password;

    //USER SELECTS WHAT TASK THEY WISH TO DO
    // 1 = USER
    // 2 = ADMIN
    cout << "Please select operation";
    if(Acctnumber == 1)
    {
        cout << "1. Deposit";
        cout << "2. Withdraw";
        cout << "3. Transfer";
        cout << "4. View History";
        cout << "5. Logout";

    }
    else if(Acctnumber ==2)
    {
        cout << "1. Create Account";
        cout << "2. Delete Account";
        cout << "3. Freeze Account";
        cout << "4. Unfreeze Account";
        cout << "5. Find Account Details";
        cout << "6. Logout";
    }
    cout << "Please enter command.";
    while(true)
    {
        cin >> input;
        switch (input){
            case 1:
            if(Acctnumber == 1)
            {

            }
            else if(Acctnumber == 2)
            {

            }

            case 2:
            if(Acctnumber == 1)
            {

            }
            else if(Acctnumber == 2)
            {
                
            }

            case 3:
            if(Acctnumber == 1)
            {

            }
            else if(Acctnumber == 2)
            {
                
            }

            case 4:
            if(Acctnumber == 1)
            {

            }
            else if(Acctnumber == 2)
            {
                
            }

            case 5:
            if(Acctnumber == 1)
            {

            }
            else if(Acctnumber == 2)
            {
                
            }

            case 6:
            if(Acctnumber == 1)
            {
                cout << "Please enter a valid value.";
            }
            else if(Acctnumber == 2)
            {
                
            }

            default:
            cout << "Please enter a valid value.";
        }
        break;
    }

    return 0;
}
