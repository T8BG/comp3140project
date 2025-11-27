#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>

class Transaction {
public:
    // Parameterized constructor
    Transaction(int transactionID, float amount, const std::string &date, 
                const std::string &type, int sourceAccount, int destinationAccount);
    
    // Default constructor
    Transaction();
    
    // Getters
    int getTransactionID() const;
    float getAmount() const;
    const std::string &getDate() const;
    const std::string &getType() const;
    int getSourceAccount() const;
    int getDestinationAccount() const;

private:
    int transactionID;
    float amount;
    std::string date;
    std::string type;
    int sourceAccount;
    int destinationAccount;
};

#endif
