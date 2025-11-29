#include "../../headers/Repository/CustomerRepository.h"

// Method to add a customer object to the customers list
void CustomerRepository::save(const Customer &customer) {
    customersList.push_back(customer);
}

// Heper method find a customer by customer ID
Customer* CustomerRepository::findByCustomerID(const std::string &customerID) {
    // iterate through all the customers and find matching customer ID
    for (auto &customer : customersList) {
        if (customer.getCustomerID() == customerID) {
            return &customer; // return pointer to the customer
        }
    }
    return nullptr; 
}

