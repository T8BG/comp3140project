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

