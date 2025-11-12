#ifndef ADMIN_H
#define ADMIN_H

#include <string>

#include "Account.h"
#include "Customer.h"

class AccountService;

// Currently have Admin inheriting from Account (might need to change that later)
class Admin : public Account{
public:
    // Parameterized  (changed username adminID same as UML)
    Admin(const std::string &adminID, int password, AccountService &accountService);

    // Create an account, pass in a customer object
    void createAccount(const Customer &customer);

    // View all accounts (returns a list of all accounts)
    void viewAllAccounts();
    
private:
    std::string adminID;
    int password;
    AccountService &accountService;
};

#endif