#include "../headers/Transactions.h"

// Parameterized constructor
Transaction::Transaction(int transactionIDValue, float amountValue, const std::string &dateValue,
                         const std::string &typeValue, int sourceAccountValue, int destinationAccountValue)
    : transactionID(transactionIDValue),
      amount(amountValue),
      date(dateValue),
      type(typeValue),
      sourceAccount(sourceAccountValue),
      destinationAccount(destinationAccountValue) {
}

// Default constructor
Transaction::Transaction()
    : transactionID(0),
      amount(0.0), 
      date(""),
      type(""),
      sourceAccount(0),
      destinationAccount(0) {}

// Getters
int Transaction::getTransactionID() const {
    return transactionID;
}

float Transaction::getAmount() const {
    return amount;
}

const std::string &Transaction::getDate() const {
    return date;
}

const std::string &Transaction::getType() const {
    return type;
}

int Transaction::getSourceAccount() const {
    return sourceAccount;
}

int Transaction::getDestinationAccount() const {
    return destinationAccount;
}

