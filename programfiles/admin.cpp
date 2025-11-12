#include "../headers/Admin.h"
#include "../headers/ServiceClass/AccountServices.h"
using namespace std;

// Parameterized constructor
Admin::Admin(const std::string &adminIDValue, int passwordValue, AccountService &service)
    : Account(),
      adminID(adminIDValue),
      password(passwordValue),
      accountService(service) {
}

// Methods will go below: 
// Create an account the custoemr, uses the AccountServices class
void Admin::createAccount(const Customer &customer) {
    accountService.createAccount(customer);
}

// View all accounts (returns a list of all accounts)
void Admin::viewAllAccounts() {
    accountService.viewAllAccounts();
}