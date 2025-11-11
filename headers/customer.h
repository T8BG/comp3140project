#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class customer {
public:
    // Parameterized Constructor
    customer(std::string username);

    // Regular Constructor
    customer();

    //Login function
    bool login(string username, string password);
};

#endif