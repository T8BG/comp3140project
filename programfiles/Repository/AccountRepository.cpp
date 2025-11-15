#include "../../headers/Repository/AccountRepository.h"
#include <iostream>
using namespace std;
// Method to save an account object to the accountsList
void AccountRepository::save(const Account &account) {
    // Just appending the account object to the end of the accountsList
    accountsList.push_back(account);
}

// Method to get all accounts numbers from the accountsList
void AccountRepository::viewAllAccounts() const {
    if (accountsList.empty()) {
        cout << "No accounts found." << endl;
        return;
    }
    
    cout << "Account Number\tAccount Holder Name" << endl;
    cout << "-----------------------------------" << endl;
    for (const auto &account : accountsList) {
        cout << account.getAccountNumber() << "\t\t" << account.getName() << endl;
    }
}

