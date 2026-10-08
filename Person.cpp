#include "Person.h"

// Default constructor
Person::Person()
{
    id = 0;
    name = "";
}

// Parameterized constructor
Person::Person(int id, string name)
{
    this->id = id;
    this->name = name;
}

// Virtual destructor
Person::~Person()
{
}

// Display person details
void Person::display() const
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
}

// Getter for ID
int Person::getId() const
{
    return id;
}

// Getter for name
string Person::getName() const
{
    return name;
}

// Setter for ID
void Person::setId(int id)
{
    this->id = id;
}

// Setter for name
void Person::setName(string name)
{
    this->name = name;
}