
#ifndef MUSICSTORE_H
#define MUSICSTORE_H

#include "Album.h"
#include "Artist.h"
#include "Customer.h"
#include "Sale.h"

class MusicStore
{
private:
    Album* albums;
    Artist* artists;
    Customer* customers;
    Sale* sales;

    int albumCount;
    int artistCount;
    int customerCount;
    int saleCount;

    int albumCapacity;
    int artistCapacity;
    int customerCapacity;
    int saleCapacity;

    // Increase array capacity when needed
    void resizeAlbums();
    void resizeArtists();
    void resizeCustomers();
    void resizeSales();

public:
    // Constructor and destructor
    MusicStore();
    ~MusicStore();

    // Add records
    void addAlbum();
    void addArtist();
    void addCustomer();

    // Display records
    void displayAlbums() const;
    void displayArtists() const;
    void displayCustomers() const;
    void displaySales() const;

    // Search records
    void searchAlbum() const;
    void searchArtist() const;
    void searchCustomer() const;

    // Update records
    void updateAlbum();
    void updateArtist();
    void updateCustomer();

    // Delete records
    void deleteAlbum();
    void deleteArtist();
    void deleteCustomer();

    // Main transaction
    void sellAlbum();

    // Reports
    void showReport() const;

    // File handling
    void saveData() const;
    void loadData();
};

#endif