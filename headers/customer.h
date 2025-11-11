#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    // Parameterized Constructor
    Customer(std::string username);

    // Regular Constructor
    Customer();

    //Login function
    bool login(std::string username, std::string password);
};

#endif