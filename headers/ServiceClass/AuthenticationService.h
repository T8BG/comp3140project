#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H

#include <string>

class Admin;
class Customer;

class AuthenticationService {
public:
    // authenticate an admin 
    bool authenticateAdmin(const Admin &admin) const;
    
    // authenticate a custoemr 
    bool authenticateCustomer(const Customer &customer) const;

private:
    // helper method to get username and password from user input
    void getCredentials(std::string &username, std::string &password) const;
};

#endif


