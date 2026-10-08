#ifndef ARTIST_H
#define ARTIST_H

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Artist : public Person
{
private:
    string genre;

public:
    // Default constructor
    Artist();

    // Parameterized constructor
    Artist(int artistId, string name, string genre);

    // Destructor
    ~Artist();

    // Override display function
    void display() const override;

    // Getter
    string getGenre() const;

    // Setter
    void setGenre(string genre);
};

#endif