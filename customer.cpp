#include "Customer.h"

// Default constructor
Customer::Customer()
{
    phone = "";
}

// Parameterized constructor
Customer::Customer(int customerId, string name, string phone)
    : Person(customerId, name)
{
    this->phone = phone;
}

// Destructor
Customer::~Customer()
{
}

// Display customer details
void Customer::display() const
{
    cout << "Customer ID: " << id << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Phone: " << phone << endl;
}

// Getter for phone
string Customer::getPhone() const
{
    return phone;
}

// Setter for phone
void Customer::setPhone(string phone)
{
    this->phone = phone;
}