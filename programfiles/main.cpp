

#include <vector>
#include <iostream>
using namespace std;

#include "../headers/Admin.h"
#include "../headers/Customer.h"
#include "../headers/Repository/AccountRepository.h"
#include "../headers/Repository/CustomerRepository.h"
#include "../headers/Repository/TransactionRepository.h"
#include "../headers/ServiceClass/AccountServices.h"
#include "../headers/ServiceClass/CustomerServices.h"
#include "../headers/ServiceClass/AuthenticationService.h"
#include "../headers/ServiceClass/TransferService.h"

int main() {
    // Create repository and servidce objects
    AccountRepository accountRepository;
    CustomerRepository customerRepository;
    TransactionRepository transactionRepository;
    AccountService accountService(accountRepository);
    CustomerService customerService(customerRepository);
    AuthenticationService authService;
    TransferService transferService(transactionRepository, accountRepository);

    // Variables for menu
    int acctType;
    int menuSelect;
    int acctNum;
    int acctTransNum;

    double value;
    
    // All new customers will start with no accounts (an empty list)
    std::vector<int> initialAccounts;

    // Create a new customer object
    Customer customer("T001","John Doe","password","123 Kamloops Ave",
        "123-456-6788","test@gmail.com",initialAccounts);

    Customer customer2("T002","John Wick","password","123 Kamloops Ave",
            "123-456-6788","test@gmail.com",initialAccounts);

    // Save customers to repository
    customerRepository.save(customer);
    customerRepository.save(customer2);

    // Create a new admin object
    Admin admin("Admin1", "password", accountService);

    // Admin then creates an account for the customer
    admin.createAccount(customer);
    admin.createAccount(customer2);
    std::cout << std::endl;

    
    
    //MAIN MENU PROMPTING
    while(true)
    {
        // Select type of account
        while(true)
        {
            cout << "What account type would you like to log into?" << std::endl;
            cout << "1. Admin" << std::endl;
            cout << "2. Customer" << std::endl;
            cout << "3. Register" << std::endl;
            cin >> acctType;
            
            if(acctType == 1 || acctType == 2)
            {
                break;
            }
            //Register
            else if (acctType == 3)
            {
                std::cout << std::endl << "=== Register New Customer ===" << std::endl;
                Customer newCustomer = customerService.createCustomer();
                std::cout << std::endl;
                continue; // go back to menu
            }
            else
            {
                cout << "Please enter 1, 2, or 3" << std::endl;
            }
        }
        
        // Log in
        bool loginSuccess = false;
        Customer* loggedInCustomer = nullptr;
        
        if(acctType == 1)
        {
            // Admin login
            std::cout << std::endl << "=== Admin Login ===" << std::endl;
            loginSuccess = authService.authenticateAdmin(admin);
        }
        else if(acctType == 2)
        {
            // Customer login
            std::cout << std::endl << "=== Customer Login ===" << std::endl;
            std::string customerID, password;
            std::cout << "Enter customer ID: ";
            std::cin >> customerID;
            std::cout << "Enter password: ";
            std::cin >> password;
            
            loggedInCustomer = customerRepository.findByCustomerID(customerID);
            if(loggedInCustomer == nullptr)
            {
                std::cout << "Customer not found." << std::endl;
                continue; // go back to menu
            }
            
            if(password == loggedInCustomer->getPassword())
            {
                loginSuccess = true;
            }
            else
            {
                std::cout << "Incorrect password." << std::endl;
            }
        }
        
        if(!loginSuccess)
        {
            std::cout << "Login failed. Returning to main menu." << std::endl << std::endl;
            continue; // go back to menu
        }

        //Main menu
        while(true)
        {
            std::cout << std::endl << "=== Main Menu ===" << std::endl;
            
            // Admin selection
            if(acctType == 1)
            {
                cout << "1. Create Account for Customer" << std::endl;
                cout << "2. Delete Account" << std::endl;
                cout << "3. View All Accounts" << std::endl;
                cout << "4. Log out" << std::endl;
                cout << "9. Exit Program" << std::endl;
            }
            // Customer selection
            else if(acctType == 2)
            {
                cout << "1. Deposit funds" << std::endl;
                cout << "2. Withdraw funds" << std::endl;
                cout << "3. Transfer funds" << std::endl;
                cout << "4. View Transaction History" << std::endl;
                cout << "5. Change Password" << std::endl;
                cout << "6. Log out" << std::endl;
                cout << "9. Exit Program" << std::endl;
            }
            
            cout << "Please enter your selection: ";
            cin >> menuSelect;
            std::cout << std::endl;

            //Has to be if-else statements in order to break properly.
            if(menuSelect == 1)
            {
                if(acctType == 1)
                {
                    
                    // Create account for customer
                    std::string customerID;
                    std::cout << "Enter customer ID to create account for: ";
                    std::cin >> customerID;
                    
                    Customer* cust = customerRepository.findByCustomerID(customerID);
                    if(cust == nullptr)
                    {
                        std::cout << "Customer not found." << std::endl;
                    }
                    else
                    {
                        admin.createAccount(*cust);
                    }
                }
                else
                {
                    cout << "Please enter account number that you wish to deposit into: ";
                    cin >> acctNum;
                    cout << "Please enter how much you wish to deposit: ";
                    cin >> value;
                    transferService.deposit(acctNum, value);
                }
            }
            else if(menuSelect == 2)
            {
                if(acctType == 1)
                {
                    // delete account
                    std::cout << "=== Delete Account ===" << std::endl;
                    std::cout << "Please enter account number: ";
                    cin >> acctNum;
                    admin.deleteAccount(acctNum);
                }
                else
                {
                    cout << "Please enter account number that you wish to withdraw from: ";
                    cin >> acctNum;
                    cout << "Please enter how much you wish to withdraw: ";
                    cin >> value;
                    transferService.withdraw(acctNum, value);
                }
            }
            else if(menuSelect == 3)
            {
                if(acctType == 1)
                {
                    // print all accounts
                    std::cout << "=== All Accounts ===" << std::endl;
                    admin.viewAllAccounts();
                }
                else
                {
                    cout << "Please enter account number that you wish to transfer from: ";
                    cin >> acctNum;
                    cout << "Please enter the account number that you wish to transfer to: ";
                    cin >> acctTransNum;
                    cout << "Please enter how much you wish to transfer: ";
                    cin >> value;
                    transferService.transfer(acctNum, acctTransNum, value);
                }
            }
            else if(menuSelect == 4)
            {
                if(acctType == 1)
                {
                    // log out
                    break;
                }
                else
                {
                    cout << "Which account would you like to see the transactions from: ";
                    cin >> acctNum;
                    std::cout << std::endl << "=== Transaction History ===" << std::endl;
                    transferService.transactionHistory(acctNum);
                }
            }
            else if(menuSelect == 5)
            {
                if(acctType == 1)
                {
                    cout << "Please select a valid menu item." << std::endl;
                }
                else
                {
                    // change password
                    if(loggedInCustomer != nullptr)
                    {
                        customerService.changePassword(loggedInCustomer->getCustomerID());
                    }
                }
            }
            else if(menuSelect == 6)
            {
                if(acctType == 2)
                {
                    // log out
                    break;
                }
                else
                {
                    cout << "Please select a valid menu item." << std::endl;
                }
            }
            else if(menuSelect == 9)
            {
                exit(0);
            }
            else
            {
                cout << "Please select a valid menu item." << std::endl;
            }
        }

    }

    return 0;
}

