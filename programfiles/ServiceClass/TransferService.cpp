#include "../../headers/ServiceClass/TransferService.h"
#include "../../headers/Transactions.h"
#include <iostream>
#include <ctime>

// Constructor (need to pass in the repo objects)
TransferService::TransferService(TransactionRepository &transactionRepo, AccountRepository &accountRepo)
    : transactionRepository(transactionRepo),
      accountRepository(accountRepo) {
}

// deposit method
void TransferService::deposit(int accountNumber, float value) {
    // find the account in the repository list and grab it's poitner
    Account* account = accountRepository.findByAccountNumber(accountNumber);
    
    if (account == nullptr) {
        std::cout << "Account not found for: " << accountNumber << std::endl;
        return;
    }
    
    // update the account balance, by adding the deposit amount to currnt balance
    account->setBalance(account->getBalance() + value); 
    
    // create a deposit transaction
    // destinationAccount = accountNumber (money going into this account) when funds come externally, sourceAccount =0 (cash, etc)
    int transactionID = generateTransactionID();
    std::string date = getCurrentDate();
    Transaction depositTransaction(transactionID, value, date, "deposit", 0, accountNumber);
    
    // save the transaction to the reposittory list
    transactionRepository.save(depositTransaction);
    
    std::cout << "Deposit of $" << value << " to account " << accountNumber << std::endl;
    std::cout << "new balance $" << account->getBalance() << std::endl;
    std::cout << "transaction ID: " << transactionID << std::endl;
}

// method to withdraw money from an account
void TransferService::withdraw(int accountNumber, float value) {
    // find the account object in the repository
    Account* account = accountRepository.findByAccountNumber(accountNumber);
    
    if (account == nullptr) {
        std::cout << "Account not found for: " << accountNumber << std::endl;
        return;
    }
    
    // check if account has sufficient balance
    float currentBalance = account->getBalance();
    if (currentBalance < value) {
        std::cout << "insuffiecnt balance: $" << currentBalance << std::endl;
        return;
    }
    
    // update the account balance
    account->setBalance(currentBalance - value);
    
    // create a tranaction object for withdralw
    // sourceAccount = accountNumber (money coming from this account), destinationAccount = 0 means external (cash etc)
    int transactionID = generateTransactionID();
    std::string date = getCurrentDate();
    Transaction withdrawTransaction(transactionID, value, date, "withdraw", accountNumber, 0);
    
    transactionRepository.save(withdrawTransaction);
    
    std::cout << "withdrawal of $" << value << " from account " << accountNumber << std::endl;
    std::cout << "new balance: $" << account->getBalance() << std::endl;
    std::cout << "transacton ID: " << transactionID << std::endl;
}

// transfer money from one account to another
void TransferService::transfer(int sourceAccount, int destinationAccount, float value) {
    // grab the account objects from the accounts repository
    Account* sourceAcc = accountRepository.findByAccountNumber(sourceAccount);
    Account* destinationAcc = accountRepository.findByAccountNumber(destinationAccount);
    
    if (sourceAcc == nullptr || destinationAcc == nullptr) {
        std::cout << "Source or destination account not found" << std::endl;
        return;
    }
        
    // check if source account has enough of a balance to transfer
    float currentBalance = sourceAcc->getBalance();
    if (currentBalance < value) {
        std::cout << "insuffiecnt balance $" << currentBalance << std::endl;
        return;
    }
    
    // update both account balances accordingky
    sourceAcc->setBalance(currentBalance - value);
    destinationAcc->setBalance(destinationAcc->getBalance() + value);
    
    // create a transfer transaction object ofr the transfer
    int transactionID = generateTransactionID();
    std::string date = getCurrentDate();
    Transaction transferTransaction(transactionID, value, date, "transfer", sourceAccount, destinationAccount);
    
    // add the transaction object to list of all transaction
    transactionRepository.save(transferTransaction);
    
    std::cout << "Transfer of $" << value << " from account " << sourceAccount << " to account " << destinationAccount << std::endl;
    std::cout << "Updated source account balance: $" << sourceAcc->getBalance() << std::endl;
    std::cout << "Updated destination account balance: $" << destinationAcc->getBalance() << std::endl;
}

// helper method to generate transaction ID
int TransferService::generateTransactionID() const {
    static int nextTransactionID = 1; // start at 1, static so it will remain in memry 
    return nextTransactionID++;
}

// helper method to get current timestamp as string - source https://www.w3schools.com/cpp/cpp_date.asp
std::string TransferService::getCurrentDate() const {
    std::time_t timestamp = std::time(nullptr);
    return std::to_string(timestamp);
}

// view all transactions for an account
void TransferService::transactionHistory(int accountNumber) const {
    std::vector<Transaction> transactions = transactionRepository.findByAccount(accountNumber);
    
    if (transactions.empty()) {
        std::cout << "No transactions found fr this account: " << accountNumber << std::endl;
    } 
    else {
        std::cout << "Transactions for account " << accountNumber << std::endl;
        for (const auto &transaction : transactions) {
            std::cout << "Tranaciton #: " << transaction.getTransactionID() 
                      << "Type: " << transaction.getType() << " "
                      << "Amont: $" << transaction.getAmount() << " "
                      << "From: " << transaction.getSourceAccount() << " "
                      << "To: " << transaction.getDestinationAccount() << " "
                      << "Date: " << transaction.getDate() << std::endl;
        }
    }
}


