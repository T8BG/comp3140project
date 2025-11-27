#ifndef TRANSFERSERVICE_H
#define TRANSFERSERVICE_H

#include "../Repository/TransactionRepository.h"
#include "../Repository/AccountRepository.h"

class TransferService {
public:
    // Constructor (pass in both transaction and account repositories)
    TransferService(TransactionRepository &transactionRepository, AccountRepository &accountRepository);
    
    // deposit money into an account
    void deposit(int accountNumber, float value);
    
    // withdraw money from an account
    void withdraw(int accountNumber, float value);
    
    // transfer money from one account to another
    void transfer(int sourceAccount, int destinationAccount, float value);
    
    // view list of all transactionfor an account
    void transactionHistory(int accountNumber) const;

private:
    TransactionRepository &transactionRepository;
    AccountRepository &accountRepository;
    
    // helper method that geneartes unique transaction ID
    int generateTransactionID() const;
    
    // helper methd to get current date as string
    std::string getCurrentDate() const;
};

#endif


