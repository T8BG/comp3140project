#ifndef CUSTOMERREPOSITORY_H
#define CUSTOMERREPOSITORY_H

#include <vector>
#include "../Customer.h"

class CustomerRepository {
public:
    // Method save a customer object to repository list
    void save(const Customer &customer);
    
    // Method that find a customer by customer ID
    Customer* findByCustomerID(const std::string &customerID);

private:
    // Vector of all customer objects
    std::vector<Customer> customersList;
};

#endif

