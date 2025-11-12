#ifndef ACCOUNTSERVICES_H
#define ACCOUNTSERVICES_H

#include "../Customer.h"
#include "../Repository/AccountRepository.h"

class AccountService {
public:
    // Constructor (passes in the repostory object)
    AccountService(AccountRepository &repository);

    // createAccount, generateAccountNumber methods 
    void createAccount(const Customer &customer);
    int generateAccountNumber() const;

    // View all accounts (returns a list of all accounts)
    void viewAllAccounts();

private:
    AccountRepository &accountRepository;
};

#endif

