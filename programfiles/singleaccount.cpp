#include "../headers/SingleAccount.h"
#include <iostream>

using namespace std;

// Create a single account for one customer
void SingleAccount::createAccount(const Customer &customer, int accountNumber) {
    // SingleAccount is for one customer only
    std::cout << "Single Account Created" << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder: " << customer.getName() << std::endl;
    std::cout << "Customer ID: " << customer.getCustomerID() << std::endl;
    std::cout << "Account Type: Single Account" << std::endl;
}