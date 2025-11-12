#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include <vector>

#include "../Account.h"

class AccountRepository {
public:
    // Method to save an account object to repository
    void save(const Account &account);
    // Method to print all stored account numbers in the repository.
    void viewAllAccounts() const;

private:
    // Vector (list) of all account objects, in the future we can save it to a file or database
    std::vector<Account> accounts_list;
};

#endif


