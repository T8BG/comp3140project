#include "../../headers/ServiceClass/CustomerServices.h"
#include "../../headers/Customer.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor takes in repository obvject 
CustomerService::CustomerService(CustomerRepository &repository)
    : customerRepository(repository) {
}

// create a new customer 
Customer CustomerService::createCustomer() {
    std::string customerID, name, password, address, phoneNumber, email;
    std::vector<int> accountNumbers; // new customers dont have any accounts
    
    std::cout << "Enter customer ID: ";
    std::cin >> customerID;
    
    std::cout << "Enter name: ";
    std::cin >> name;
    
    std::cout << "Enter password: ";
    std::cin >> password;
    
    std::cout << "Enter address: ";
    std::cin >> address;
    
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    
    std::cout << "Enter email: ";
    std::cin >> email;
    
    // create the customer object
    Customer newCustomer(customerID, name, password, address, phoneNumber, email, accountNumbers);
    
    // save to repository
    customerRepository.save(newCustomer);
    
    std::cout << "Customer created - ID: " << customerID << std::endl;
    std::cout << "Name: " << name << std::endl;
    
    return newCustomer;
}

// change password for a customer
void CustomerService::changePassword(const std::string &customerID) {
    // grab the customer object from the repository if it exisits 
    Customer* customer = customerRepository.findByCustomerID(customerID);
    
    // customer does not exist 
    if (customer == nullptr) {
        std::cout << "Customer not found: " << customerID << std::endl;
        return;
    }
    
    // grab the new password from user
    std::string newPassword;
    std::cout << "Enter new password for customer " << customerID << ": ";
    std::cin >> newPassword;
    
    // use setter to change the paswrod for the customer
    customer->setPassword(newPassword);
    std::cout << "Password changed successfully for customer " << customerID << std::endl;
}

