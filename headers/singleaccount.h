#ifndef SINGLEACCOUNT_H
#define SINGLEACCOUNT_H

#include <iostream>
#include "../headers/Account.h"
#include "../headers/Customer.h"

class SingleAccount: public Account{
public:
    // Create a single account for one customer
    void createAccount(const Customer &customer, int accountNumber);
};

#endif