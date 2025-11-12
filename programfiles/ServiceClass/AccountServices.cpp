#include "../../headers/ServiceClass/AccountServices.h"
#include "../../headers/Repository/AccountRepository.h"
#include <iostream>

// Constructor (passes in the repostory object)
AccountService::AccountService(AccountRepository &repository)
    : accountRepository(repository) {
}

// createAccount method, creats an account for the customer 
void AccountService::createAccount(const Customer &customer) {
    int accountNumber = generateAccountNumber();
    Account newAccount(accountNumber, customer.getName());

    accountRepository.save(newAccount);

    std::cout << "new account created for " << customer.getName() << " account number " << accountNumber << std::endl;
}

// Simple method that just creates a new account number by adding 1 to the prevousily created number
int AccountService::generateAccountNumber() const {
    static int nextAccountNumber = 1000; // Static lets us keep track of next account numbr
    return nextAccountNumber++;
}

// View all accounts stored in the repository
void AccountService::viewAllAccounts() {
    accountRepository.viewAllAccounts();
}