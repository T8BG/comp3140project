#include "../headers/Admin.h"
#include "../headers/ServiceClass/AccountServices.h"
using namespace std;

// Parameterized constructor
Admin::Admin(const std::string &adminIDValue, string passwordValue, AccountService &service)
    : Account(),
      adminID(adminIDValue),
      password(passwordValue),
      accountService(service) {
}

// Methods will go below: 
// Create an account the custoemr, uses the AccountServices class
void Admin::createAccount(const Customer &customer) {
    accountService.createAccount(customer);
}

//Login
bool Admin::login() const
{
    bool result = false;
    string name;
    string password;
    while(true)
    {
        cout << "Please enter your username: ";
        cin >> name;
        cout << "Please enter your password: ";
        cin >> password;

        if(name == getAdminID() && password == getPassword())
        {
            result = true;
            break;
        }
        else
        {
            cout << "Your username or password is incorrect, please try again.";
        };
    }    
    return result;
}

// View all accounts (returns a list of all accounts)
void Admin::viewAllAccounts() {
    accountService.viewAllAccounts();
}

//getters
const std::string &Admin::getAdminID() const {return adminID;}
const std::string &Admin::getPassword() const {return password;}