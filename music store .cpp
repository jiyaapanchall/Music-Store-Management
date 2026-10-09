
#include "MusicStore.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>

using namespace std;

// Initial capacity for each dynamic array
const int INITIAL_CAPACITY = 5;

// Constructor
MusicStore::MusicStore()
{
    albumCapacity = INITIAL_CAPACITY;
    artistCapacity = INITIAL_CAPACITY;
    customerCapacity = INITIAL_CAPACITY;
    saleCapacity = INITIAL_CAPACITY;

    albumCount = 0;
    artistCount = 0;
    customerCount = 0;
    saleCount = 0;

    albums = new Album[albumCapacity];
    artists = new Artist[artistCapacity];
    customers = new Customer[customerCapacity];
    sales = new Sale[saleCapacity];
}

// Destructor
MusicStore::~MusicStore()
{
    delete[] albums;
    delete[] artists;
    delete[] customers;
    delete[] sales;
}

// Increase album array capacity
void MusicStore::resizeAlbums()
{
    int newCapacity = albumCapacity * 2;
    Album* newAlbums = new Album[newCapacity];

    for (int i = 0; i < albumCount; i++)
    {
        newAlbums[i] = albums[i];
    }

    delete[] albums;
    albums = newAlbums;
    albumCapacity = newCapacity;
}

// Increase artist array capacity
void MusicStore::resizeArtists()
{
    int newCapacity = artistCapacity * 2;
    Artist* newArtists = new Artist[newCapacity];

    for (int i = 0; i < artistCount; i++)
    {
        newArtists[i] = artists[i];
    }

    delete[] artists;
    artists = newArtists;
    artistCapacity = newCapacity;
}

// Increase customer array capacity
void MusicStore::resizeCustomers()
{
    int newCapacity = customerCapacity * 2;
    Customer* newCustomers = new Customer[newCapacity];

    for (int i = 0; i < customerCount; i++)
    {
        newCustomers[i] = customers[i];
    }

    delete[] customers;
    customers = newCustomers;
    customerCapacity = newCapacity;
}

// Increase sales array capacity
void MusicStore::resizeSales()
{
    int newCapacity = saleCapacity * 2;
    Sale* newSales = new Sale[newCapacity];

    for (int i = 0; i < saleCount; i++)
    {
        newSales[i] = sales[i];
    }

    delete[] sales;
    sales = newSales;
    saleCapacity = newCapacity;
}