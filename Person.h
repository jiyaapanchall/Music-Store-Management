#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    // Default constructor
    Person();

    // Parameterized constructor
    Person(int id, string name);

    // Virtual destructor
    virtual ~Person();

    // Virtual display function
    virtual void display() const;

    // Getters
    int getId() const;
    string getName() const;

    // Setters
    void setId(int id);
    void setName(string name);
};

#endif