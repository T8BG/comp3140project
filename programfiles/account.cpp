#include "../headers/Account.h"

using namespace std;

// Parameterized Constructor
Account::Account(int accountNumber, const std::string &name)
    : accountNumber(accountNumber),
      name(name),
      balance(0.0) {
}

// Default Constructor
Account::Account()
    : accountNumber(0),
      name(""),
      balance(0.0) {
}

// Getters
int Account::getAccountNumber() const {
    return accountNumber;
}

const std::string &Account::getName() const {
    return name;
}

float Account::getBalance() const {
    return balance;
}

// Setters
void Account::setBalance(float balance) {
    this->balance = balance;
}

