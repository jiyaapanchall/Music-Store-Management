#include "Artist.h"

// Default constructor
Artist::Artist()
{
    genre = "";
}

// Parameterized constructor
Artist::Artist(int artistId, string name, string genre)
    : Person(artistId, name)
{
    this->genre = genre;
}

// Destructor
Artist::~Artist()
{
}

// Display artist details
void Artist::display() const
{
    cout << "Artist ID: " << id << endl;
    cout << "Artist Name: " << name << endl;
    cout << "Genre: " << genre << endl;
}

// Getter for genre
string Artist::getGenre() const
{
    return genre;
}

// Setter for genre
void Artist::setGenre(string genre)
{
    this->genre = genre;
}