#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector> // for array of account numbers

class Customer {
public:
    // Constructor with the required fields
    Customer(const std::string &customerID, const std::string &name, const std::string &password, 
        const std::string &address, const std::string &phoneNumber, const std::string &email, const std::vector<int> &accountNumbers);
    // Default constructor
    Customer();

    // Getters for the customer's data
    const std::string &getName() const;
    const std::string &getCustomerID() const;
    const std::string &getPassword() const;
    const std::string &getAddress() const;
    const std::string &getPhoneNumber() const;
    const std::string &getEmail() const;
    const std::vector<int> &getAccountNumbers() const; // vector of account numbers

    bool login() const;

private:
    std::string name;
    std::string customerID;
    std::string password;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::vector<int> accountNumbers;
};

#endif