#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

#include <vector>
#include "../Transactions.h"

class TransactionRepository {
public:
    // Method to add transaction object to the vector containing all transactions
    void save(const Transaction &transaction);
    
    // Method find all transactions of an account
    std::vector<Transaction> findByAccount(int accountNumber) const;

private:
    // Vecto of all transaction objects
    std::vector<Transaction> transactionsList;
};

#endif


