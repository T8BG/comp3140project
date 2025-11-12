#include "../../headers/Repository/AccountRepository.h"
#include <iostream>
using namespace std;
// Method to save an account object to the accounts_list
void AccountRepository::save(const Account &account) {
    // Just appending the account object to the end of the accounts_list
    accounts_list.push_back(account);
}

// Method to get all accounts numbers from the accounts_list
void AccountRepository::viewAllAccounts() const {
    for (const auto &account : accounts_list) {
        cout << account.getAccountNumber() << endl;
    }
}

