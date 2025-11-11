#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account{
public:
    // Parameterized Constructor (changed the parameter from username to name for consistency)
    Account(int accountNumber, const std::string &name);

    // Default Constructor
    Account();
    
    // Getters
    int getAccountNumber() const;
    const std::string &getName() const;

private:
    int accountNumber;
    std::string name;
};

#endif