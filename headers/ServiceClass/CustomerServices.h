#ifndef CUSTOMERSERVICES_H
#define CUSTOMERSERVICES_H

#include "../Repository/CustomerRepository.h"

class CustomerService {
public:
    // Constructor
    CustomerService(CustomerRepository &repository);
    
    // create a new customer 
    Customer createCustomer();
    
    // change password for a customer
    void changePassword(const std::string &customerID);

private:
    CustomerRepository &customerRepository;
};

#endif

