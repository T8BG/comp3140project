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
        cout << "No accounts found" << endl;
        return;
    }
    
    // print all accounts and their attributes (balnce etc)
    cout << "Account Number \t Account Holder Name \t Balance" << endl;
    cout << "-----------------------------------------------" << endl;
    for (const auto &account : accountsList) {
        cout << account.getAccountNumber() << "\t\t" << account.getName() << "\t\t$" << account.getBalance() << endl;
    }
}

// Method to delete an account usin the account number from the accountsList vectir
bool AccountRepository::deleteAccount(int accountNumber) {
    // Iterate through the accountsList and find the machting account number
    for (auto i = accountsList.begin(); i != accountsList.end(); ++i) {
        if (i->getAccountNumber() == accountNumber) {
            // found it, delete and return true
            accountsList.erase(i); 
            return true; 
        }
    }
    return false; // account not found
}

// Method to find an account by account number (returns pointer of account object or noll if not found)
// pointer is needed so we can access/modify individual account attributes like balance, etc
Account* AccountRepository::findByAccountNumber(int accountNumber) {
    // iterate through accounts and find the matching account number
    for (auto &account : accountsList) {
        if (account.getAccountNumber() == accountNumber) {
            return &account; 
        }
    }
    return nullptr; // account not found
}

