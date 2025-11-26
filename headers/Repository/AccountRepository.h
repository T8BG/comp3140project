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
    // Method thatdelete an account by acount number
    bool deleteAccount(int accountNumber);

private:
    // Vector (list) of all account objects, in the future we can save it to a file or database
    std::vector<Account> accountsList;
};

#endif


