#include <iostream>
#include "../headers/Customer.h"
using namespace std;
// Parameterized Constructor
Customer::Customer(const std::string &name, const std::string &customerID, const std::string &password, const std::string &address, const std::string &phoneNumber, const std::string &email, const std::vector<int> &accountNumbers)
    : name(name), customerID(customerID), password(password), address(address), phoneNumber(phoneNumber), email(email), accountNumbers(accountNumbers) {
}

// Default Constructor
Customer::Customer()
    : name(""), customerID(""), password(""), address(""), phoneNumber(""), email(""), accountNumbers(0) {
}

//Login 
bool Customer::login() const
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

        if(name == getCustomerID() && password == getPassword())
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

// Getters for the customer's data
const std::string &Customer::getName() const { return name; }
const std::string &Customer::getCustomerID() const { return customerID; }
const std::string &Customer::getPassword() const { return password; }
const std::string &Customer::getAddress() const { return address; }
const std::string &Customer::getPhoneNumber() const { return phoneNumber; }
const std::string &Customer::getEmail() const { return email; }
const std::vector<int> &Customer::getAccountNumbers() const { return accountNumbers; } // returns a list of account numbers associated with the customer