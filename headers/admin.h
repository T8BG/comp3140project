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
    Admin(const std::string &adminID, string password, AccountService &accountService);

    // Create an account, pass in a customer object
    void createAccount(const Customer &customer);

    // View all accounts (returns a list of all accounts)
    void viewAllAccounts();

    //getters
    const std::string &getAdminID() const;
    const std::string &getPassword() const;

    bool login() const;
    
private:
    std::string adminID;
    std::string password;
    AccountService &accountService;
};

#endif