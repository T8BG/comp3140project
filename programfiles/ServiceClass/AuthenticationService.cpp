#include "../../headers/ServiceClass/AuthenticationService.h"
#include "../../headers/Admin.h"
#include "../../headers/Customer.h"
#include <iostream>
using namespace std;

// max fails
int maxFailCount = 3;

// authenticate an admin login
bool AuthenticationService::authenticateAdmin(const Admin &admin) const {
    string username;
    string password;

    int failCount = 0;

    // call the getCredentials method to get the username and password from the user
    while(true) {
        getCredentials(username, password);
        
        if(username == admin.getAdminID() && password == admin.getPassword()) {
            return true;
        }
        else {
            cout << "Your username or password is incorrect, please try again." << endl;
            failCount++;   
        }

        if(failCount >= maxFailCount) {
            cout << "You have been locked out of the system for 3 attempts, please try again later." << endl;
            return false;
        }
    }

}

// authenticate customer login
bool AuthenticationService::authenticateCustomer(const Customer &customer) const {
    string username;
    string password;

    int failCount = 0;
    
    while(true) {
        getCredentials(username, password);
        
        if(username == customer.getCustomerID() && password == customer.getPassword()) {
            return true;
        }
        else {
            cout << "Your username or password is incorrect, please try again." << endl;
            failCount++;
        }


        if(failCount >= maxFailCount) {
            cout << "You have been locked out of the system for 3 attempts, please try again later." << endl;
            return false;
        }
    }
    
}

// helper method to get username and password from user
void AuthenticationService::getCredentials(std::string &username, std::string &password) const {
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
}


