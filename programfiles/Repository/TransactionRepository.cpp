#include "../../headers/Repository/TransactionRepository.h"

// Method to save a transaction object to the transactionsList
void TransactionRepository::save(const Transaction &transaction) {
    // Just appending the transaction object to the end of the transactionsList
    transactionsList.push_back(transaction);
}

// Method to find all transactions for a specific account
std::vector<Transaction> TransactionRepository::findByAccount(int accountNumber) const {
    std::vector<Transaction> result;
    
    // iterate through transactions and find ones matching the account number
    for (const auto &transaction : transactionsList) {
        // check if account is source or destination
        if (transaction.getSourceAccount() == accountNumber || 
            transaction.getDestinationAccount() == accountNumber) {
            result.push_back(transaction);
        }
    }
    
    return result;
}


