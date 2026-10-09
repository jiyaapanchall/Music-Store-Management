#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
using namespace std;

class Album
{
private:
    int albumId;
    string title;
    int artistId;
    double price;
    int stock;

public:
    // Default constructor
    Album();

    // Parameterized constructor
    Album(int albumId, string title, int artistId, double price, int stock);

    // Destructor
    ~Album();

    // Display album details
    void display() const;

    // Update stock
    void updateStock(int quantity);

    // Getters
    int getAlbumId() const;
    string getTitle() const;
    int getArtistId() const;
    double getPrice() const;
    int getStock() const;

    // Setters
    void setTitle(string title);
    void setArtistId(int artistId);
    void setPrice(double price);
    void setStock(int stock);
};

#endif