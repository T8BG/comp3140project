#ifndef ACCOUNTSERVICES_H
#define ACCOUNTSERVICES_H

#include "../Customer.h"
#include "../Repository/AccountRepository.h"

class AccountService {
public:
    // Constructor (passes in the repostory object)
    AccountService(AccountRepository &repository);

    // createAccount, generateAccountNumber, deleteAccount methods 
    void createAccount(const Customer &customer);
    int generateAccountNumber() const;
    void deleteAccount(Customer &customer);

    // View all accounts (returns a list of all accounts)
    void viewAllAccounts();

    //Freeze and unfreeze methods
    void freezeAccount(const std::string &customerID);

    void unfreezeAccount(const std::string &customerID);

private:
    AccountRepository &accountRepository;
};

#endif

