#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Customer : public Person
{
private:
    string phone;

public:
    // Default constructor
    Customer();

    // Parameterized constructor
    Customer(int customerId, string name, string phone);

    // Destructor
    ~Customer();

    // Override display function
    void display() const override;

    // Getter
    string getPhone() const;

    // Setter
    void setPhone(string phone);
};

#endif