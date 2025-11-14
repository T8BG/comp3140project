#include "../headers/Account.h"

using namespace std;

// Parameterized Constructor
Account::Account(int accountNumber, const std::string &name)
    : accountNumber(accountNumber),
      name(name) {
}

// Default Constructor
Account::Account()
    : accountNumber(0),
      name("") {
}

// Getters
int Account::getAccountNumber() const {
    return accountNumber;
}

const std::string &Account::getName() const {
    return name;
}

