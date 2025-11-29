#include "../../headers/ServiceClass/AuthenticationService.h"
#include "../../headers/Admin.h"
#include "../../headers/Customer.h"
#include <iostream>
using namespace std;

// authenticate an admin login
bool AuthenticationService::authenticateAdmin(const Admin &admin) const {
    bool result = false;
    string username;
    string password;

    // call the getCredentials method to get the username and password from the user
    while(true) {
        getCredentials(username, password);
        
        if(username == admin.getAdminID() && password == admin.getPassword()) {
            result = true;
            break;
        }
        else {
            cout << "Your username or password is incorrect, please try again." << endl;
        }
    }
    
    return result;
}

// authenticate customer login
bool AuthenticationService::authenticateCustomer(const Customer &customer) const {
    bool result = false;
    string username;
    string password;
    
    while(true) {
        getCredentials(username, password);
        
        if(username == customer.getCustomerID() && password == customer.getPassword()) {
            result = true;
            break;
        }
        else {
            cout << "Your username or password is incorrect, please try again." << endl;
        }
    }
    
    return result;
}

// helper method to get username and password from user
void AuthenticationService::getCredentials(std::string &username, std::string &password) const {
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
}


