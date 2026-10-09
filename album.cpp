#include "Album.h"

// Default constructor
Album::Album()
{
    albumId = 0;
    title = "";
    artistId = 0;
    price = 0.0;
    stock = 0;
}

// Parameterized constructor
Album::Album(int albumId, string title, int artistId, double price, int stock)
{
    this->albumId = albumId;
    this->title = title;
    this->artistId = artistId;
    this->price = price;
    this->stock = stock;
}

// Destructor
Album::~Album()
{
}

// Display album details
void Album::display() const
{
    cout << "Album ID: " << albumId << endl;
    cout << "Title: " << title << endl;
    cout << "Artist ID: " << artistId << endl;
    cout << "Price: " << price << endl;
    cout << "Stock: " << stock << endl;
}

// Update stock
void Album::updateStock(int quantity)
{
    stock += quantity;
}

// Getter for album ID
int Album::getAlbumId() const
{
    return albumId;
}

// Getter for title
string Album::getTitle() const
{
    return title;
}

// Getter for artist ID
int Album::getArtistId() const
{
    return artistId;
}

// Getter for price
double Album::getPrice() const
{
    return price;
}

// Getter for stock
int Album::getStock() const
{
    return stock;
}

// Setter for title
void Album::setTitle(string title)
{
    this->title = title;
}

// Setter for artist ID
void Album::setArtistId(int artistId)
{
    this->artistId = artistId;
}

// Setter for price
void Album::setPrice(double price)
{
    this->price = price;
}

// Setter for stock
void Album::setStock(int stock)
{
    this->stock = stock;
}