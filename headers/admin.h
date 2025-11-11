#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin : public Account{
     //Parameterized Constructor
     Admin(std::string username);
     // Regular Constructor
     Admin();
};

#endif