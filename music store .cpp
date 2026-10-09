
#include "MusicStore.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

namespace
{
    const int INITIAL_CAPACITY = 5;

    int readInt(const string& prompt)
    {
        int value;

        while (true)
        {
            cout << prompt;

            if (cin >> value)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }

            cout << "Invalid input. Enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    double readDouble(const string& prompt)
    {
        double value;

        while (true)
        {
            cout << prompt;

            if (cin >> value)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (value >= 0)
                    return value;
            }

            cout << "Invalid input. Enter a non-negative number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    string readText(const string& prompt)
    {
        string value;

        while (true)
        {
            cout << prompt;
            getline(cin, value);

            if (!value.empty() &&
                value.find('|') == string::npos)
            {
                return value;
            }

            cout << "Input cannot be empty or contain '|'.\n";
        }
    }
}

// =====================================================
// CONSTRUCTOR AND DESTRUCTOR
// =====================================================

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

MusicStore::~MusicStore()
{
    delete[] albums;
    delete[] artists;
    delete[] customers;
    delete[] sales;
}

// =====================================================
// DYNAMIC ARRAY RESIZING
// =====================================================

void MusicStore::resizeAlbums()
{
    int newCapacity = albumCapacity * 2;
    Album* temp = new Album[newCapacity];

    for (int i = 0; i < albumCount; i++)
        temp[i] = albums[i];

    delete[] albums;
    albums = temp;
    albumCapacity = newCapacity;
}

void MusicStore::resizeArtists()
{
    int newCapacity = artistCapacity * 2;
    Artist* temp = new Artist[newCapacity];

    for (int i = 0; i < artistCount; i++)
        temp[i] = artists[i];

    delete[] artists;
    artists = temp;
    artistCapacity = newCapacity;
}

void MusicStore::resizeCustomers()
{
    int newCapacity = customerCapacity * 2;
    Customer* temp = new Customer[newCapacity];

    for (int i = 0; i < customerCount; i++)
        temp[i] = customers[i];

    delete[] customers;
    customers = temp;
    customerCapacity = newCapacity;
}

void MusicStore::resizeSales()
{
    int newCapacity = saleCapacity * 2;
    Sale* temp = new Sale[newCapacity];

    for (int i = 0; i < saleCount; i++)
        temp[i] = sales[i];

    delete[] sales;
    sales = temp;
    saleCapacity = newCapacity;
}

// =====================================================
// ADD ARTIST
// =====================================================

void MusicStore::addArtist()
{
    int id = readInt("Enter Artist ID: ");

    if (id <= 0)
    {
        cout << "ID must be positive.\n";
        return;
    }

    for (int i = 0; i < artistCount; i++)
    {
        if (artists[i].getId() == id)
        {
            cout << "Artist ID already exists.\n";
            return;
        }
    }

    string name = readText("Enter Artist Name: ");
    string genre = readText("Enter Genre: ");

    if (artistCount == artistCapacity)
        resizeArtists();

    artists[artistCount++] = Artist(id, name, genre);

    cout << "Artist added successfully!\n";
}

// =====================================================
// ADD CUSTOMER
// =====================================================

void MusicStore::addCustomer()
{
    int id = readInt("Enter Customer ID: ");

    if (id <= 0)
    {
        cout << "ID must be positive.\n";
        return;
    }

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getId() == id)
        {
            cout << "Customer ID already exists.\n";
            return;
        }
    }

    string name = readText("Enter Customer Name: ");
    string phone = readText("Enter Phone Number: ");

    if (customerCount == customerCapacity)
        resizeCustomers();

    customers[customerCount++] = Customer(id, name, phone);

    cout << "Customer added successfully!\n";
}

// =====================================================
// ADD ALBUM
// =====================================================

void MusicStore::addAlbum()
{
    int id = readInt("Enter Album ID: ");

    if (id <= 0)
    {
        cout << "ID must be positive.\n";
        return;
    }

    for (int i = 0; i < albumCount; i++)
    {
        if (albums[i].getAlbumId() == id)
        {
            cout << "Album ID already exists.\n";
            return;
        }
    }

    int artistId = readInt("Enter Artist ID: ");
    bool artistFound = false;

    for (int i = 0; i < artistCount; i++)
    {
        if (artists[i].getId() == artistId)
        {
            artistFound = true;
            break;
        }
    }

    if (!artistFound)
    {
        cout << "Artist not found. Add the artist first.\n";
        return;
    }

    string title = readText("Enter Album Title: ");
    double price = readDouble("Enter Album Price: ");
    int stock = readInt("Enter Stock Quantity: ");

    if (price <= 0 || stock < 0)
    {
        cout << "Price must be positive and stock cannot be negative.\n";
        return;
    }

    if (albumCount == albumCapacity)
        resizeAlbums();

    albums[albumCount++] =
        Album(id, title, artistId, price, stock);

    cout << "Album added successfully!\n";
}

// =====================================================
// DISPLAY RECORDS
// =====================================================

void MusicStore::displayArtists() const
{
    if (artistCount == 0)
    {
        cout << "No artists available.\n";
        return;
    }

    cout << "\n========== ARTISTS ==========\n";

    for (int i = 0; i < artistCount; i++)
    {
        artists[i].display();
        cout << "-----------------------------\n";
    }
}

void MusicStore::displayCustomers() const
{
    if (customerCount == 0)
    {
        cout << "No customers available.\n";
        return;
    }

    cout << "\n========== CUSTOMERS ==========\n";

    for (int i = 0; i < customerCount; i++)
    {
        customers[i].display();
        cout << "-------------------------------\n";
    }
}

void MusicStore::displayAlbums() const
{
    if (albumCount == 0)
    {
        cout << "No albums available.\n";
        return;
    }

    cout << "\n========== ALBUMS ==========\n";

    for (int i = 0; i < albumCount; i++)
    {
        albums[i].display();
        cout << "----------------------------\n";
    }
}

void MusicStore::displaySales() const
{
    if (saleCount == 0)
    {
        cout << "No sales recorded.\n";
        return;
    }

    cout << "\n========== SALES ==========\n";

    for (int i = 0; i < saleCount; i++)
    {
        sales[i].display();
        cout << "---------------------------\n";
    }
}

// =====================================================
// SEARCH RECORDS
// =====================================================

void MusicStore::searchAlbum() const
{
    int id = readInt("Enter Album ID to search: ");

    for (int i = 0; i < albumCount; i++)
    {
        if (albums[i].getAlbumId() == id)
        {
            cout << "\nAlbum found!\n";
            albums[i].display();
            return;
        }
    }

    cout << "Album not found.\n";
}

void MusicStore::searchArtist() const
{
    int id = readInt("Enter Artist ID to search: ");

    for (int i = 0; i < artistCount; i++)
    {
        if (artists[i].getId() == id)
        {
            cout << "\nArtist found!\n";
            artists[i].display();
            return;
        }
    }

    cout << "Artist not found.\n";
}

void MusicStore::searchCustomer() const
{
    int id = readInt("Enter Customer ID to search: ");

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getId() == id)
        {
            cout << "\nCustomer found!\n";
            customers[i].display();
            return;
        }
    }

    cout << "Customer not found.\n";
}

// =====================================================
// UPDATE ALBUM
// =====================================================

void MusicStore::updateAlbum()
{
    int id = readInt("Enter Album ID to update: ");

    for (int i = 0; i < albumCount; i++)
    {
        if (albums[i].getAlbumId() == id)
        {
            cout << "1. Update title\n";
            cout << "2. Update artist\n";
            cout << "3. Update price\n";
            cout << "4. Update stock\n";

            int choice = readInt("Choose an option: ");

            if (choice == 1)
            {
                albums[i].setTitle(readText("New title: "));
            }
            else if (choice == 2)
            {
                int artistId = readInt("New Artist ID: ");
                bool found = false;

                for (int j = 0; j < artistCount; j++)
                {
                    if (artists[j].getId() == artistId)
                        found = true;
                }

                if (!found)
                {
                    cout << "Artist not found.\n";
                    return;
                }

                albums[i].setArtistId(artistId);
            }
            else if (choice == 3)
            {
                double price = readDouble("New price: ");

                if (price <= 0)
                {
                    cout << "Price must be positive.\n";
                    return;
                }

                albums[i].setPrice(price);
            }
            else if (choice == 4)
            {
                int stock = readInt("New stock quantity: ");

                if (stock < 0)
                {
                    cout << "Stock cannot be negative.\n";
                    return;
                }

                albums[i].setStock(stock);
            }
            else
            {
                cout << "Invalid option.\n";
                return;
            }

            cout << "Album updated successfully.\n";
            return;
        }
    }

    cout << "Album not found.\n";
}

// =====================================================
// UPDATE ARTIST
// =====================================================

void MusicStore::updateArtist()
{
    int id = readInt("Enter Artist ID to update: ");

    for (int i = 0; i < artistCount; i++)
    {
        if (artists[i].getId() == id)
        {
            cout << "1. Update name\n";
            cout << "2. Update genre\n";

            int choice = readInt("Choose an option: ");

            if (choice == 1)
            {
                artists[i].setName(readText("New name: "));
            }
            else if (choice == 2)
            {
                artists[i].setGenre(readText("New genre: "));
            }
            else
            {
                cout << "Invalid option.\n";
                return;
            }

            cout << "Artist updated successfully.\n";
            return;
        }
    }

    cout << "Artist not found.\n";
}

// =====================================================
// UPDATE CUSTOMER
// =====================================================

void MusicStore::updateCustomer()
{
    int id = readInt("Enter Customer ID to update: ");

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getId() == id)
        {
            cout << "1. Update name\n";
            cout << "2. Update phone\n";

            int choice = readInt("Choose an option: ");

            if (choice == 1)
            {
                customers[i].setName(readText("New name: "));
            }
            else if (choice == 2)
            {
                customers[i].setPhone(readText("New phone: "));
            }
            else
            {
                cout << "Invalid option.\n";
                return;
            }

            cout << "Customer updated successfully.\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

// =====================================================
// DELETE ALBUM
// =====================================================

void MusicStore::deleteAlbum()
{
    int id = readInt("Enter Album ID to delete: ");

    for (int i = 0; i < albumCount; i++)
    {
        if (albums[i].getAlbumId() == id)
        {
            for (int j = 0; j < saleCount; j++)
            {
                if (sales[j].getAlbumId() == id)
                {
                    cout << "Cannot delete: this album has sales records.\n";
                    return;
                }
            }

            for (int j = i; j < albumCount - 1; j++)
                albums[j] = albums[j + 1];

            albumCount--;
            cout << "Album deleted successfully.\n";
            return;
        }
    }

    cout << "Album not found.\n";
}

// =====================================================
// DELETE ARTIST
// =====================================================

void MusicStore::deleteArtist()
{
    int id = readInt("Enter Artist ID to delete: ");

    for (int i = 0; i < artistCount; i++)
    {
        if (artists[i].getId() == id)
        {
            for (int j = 0; j < albumCount; j++)
            {
                if (albums[j].getArtistId() == id)
                {
                    cout << "Cannot delete: artist has albums.\n";
                    return;
                }
            }

            for (int j = i; j < artistCount - 1; j++)
                artists[j] = artists[j + 1];

            artistCount--;
            cout << "Artist deleted successfully.\n";
            return;
        }
    }

    cout << "Artist not found.\n";
}

// =====================================================
// DELETE CUSTOMER
// =====================================================

void MusicStore::deleteCustomer()
{
    int id = readInt("Enter Customer ID to delete: ");

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getId() == id)
        {
            for (int j = 0; j < saleCount; j++)
            {
                if (sales[j].getCustomerId() == id)
                {
                    cout << "Cannot delete: customer has sales records.\n";
                    return;
                }
            }

            for (int j = i; j < customerCount - 1; j++)
                customers[j] = customers[j + 1];

            customerCount--;
            cout << "Customer deleted successfully.\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

// =====================================================
// MAIN TRANSACTION: SELL ALBUM
// =====================================================

void MusicStore::sellAlbum()
{
    if (albumCount == 0)
    {
        cout << "No albums available for sale.\n";
        return;
    }

    if (customerCount == 0)
    {
        cout << "Add a customer before making a sale.\n";
        return;
    }

    int customerId = readInt("Enter Customer ID: ");
    bool customerFound = false;

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getId() == customerId)
            customerFound = true;
    }

    if (!customerFound)
    {
        cout << "Customer not found.\n";
        return;
    }

    int albumId = readInt("Enter Album ID: ");
    int albumIndex = -1;

    for (int i = 0; i < albumCount; i++)
    {
        if (albums[i].getAlbumId() == albumId)
        {
            albumIndex = i;
            break;
        }
    }

    if (albumIndex == -1)
    {
        cout << "Album not found.\n";
        return;
    }

    int quantity = readInt("Enter quantity: ");

    if (quantity <= 0)
    {
        cout << "Quantity must be positive.\n";
        return;
    }

    if (quantity > albums[albumIndex].getStock())
    {
        cout << "Insufficient stock. Available: "
             << albums[albumIndex].getStock() << "\n";
        return;
    }

    if (saleCount == saleCapacity)
        resizeSales();

    int nextSaleId = 1;

    for (int i = 0; i < saleCount; i++)
    {
        if (sales[i].getSaleId() >= nextSaleId)
            nextSaleId = sales[i].getSaleId() + 1;
    }

    Sale newSale(
        nextSaleId,
        albumId,
        customerId,
        quantity,
        0.0
    );

    double total = newSale.calculateTotal(
        albums[albumIndex].getPrice()
    );

    newSale.setTotal(total);
    sales[saleCount++] = newSale;

    albums[albumIndex].updateStock(-quantity);

    cout << fixed << setprecision(2);
    cout << "\n========== SALE RECEIPT ==========\n";
    cout << "Sale ID: " << nextSaleId << "\n";
    cout << "Customer: " << customers[0].getName() << "\n";
    cout << "Album: " << albums[albumIndex].getTitle() << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Unit Price: " << albums[albumIndex].getPrice() << "\n";
    cout << "Total Amount: " << total << "\n";
    cout << "Remaining Stock: "
         << albums[albumIndex].getStock() << "\n";
    cout << "==================================\n";
}

// =====================================================
// SALES REPORT
// =====================================================

void MusicStore::showReport() const
{
    double revenue = 0.0;
    int unitsSold = 0;

    for (int i = 0; i < saleCount; i++)
    {
        revenue += sales[i].getTotal();
        unitsSold += sales[i].getQuantity();
    }

    cout << "\n========== STORE REPORT ==========\n";
    cout << "Total Artists: " << artistCount << "\n";
    cout << "Total Customers: " << customerCount << "\n";
    cout << "Total Albums: " << albumCount << "\n";
    cout << "Total Sales Transactions: " << saleCount << "\n";
    cout << "Total Units Sold: " << unitsSold << "\n";
    cout << fixed << setprecision(2);
    cout << "Total Revenue: " << revenue << "\n";
    cout << "==================================\n";
}

// =====================================================
// SAVE DATA TO TEXT FILES
// Files are created in the program's working directory.
// =====================================================

void MusicStore::saveData() const
{
    ofstream artistFile("artists.txt");
    ofstream customerFile("customers.txt");
    ofstream albumFile("albums.txt");
    ofstream saleFile("sales.txt");

    if (!artistFile || !customerFile || !albumFile || !saleFile)
    {
        cout << "Error: Could not open data files for saving.\n";
        return;
    }

    for (int i = 0; i < artistCount; i++)
    {
        artistFile << artists[i].getId() << "|"
                   << artists[i].getName() << "|"
                   << artists[i].getGenre() << "\n";
    }

    for (int i = 0; i < customerCount; i++)
    {
        customerFile << customers[i].getId() << "|"
                     << customers[i].getName() << "|"
                     << customers[i].getPhone() << "\n";
    }

    for (int i = 0; i < albumCount; i++)
    {
        albumFile << albums[i].getAlbumId() << "|"
                  << albums[i].getTitle() << "|"
                  << albums[i].getArtistId() << "|"
                  << albums[i].getPrice() << "|"
                  << albums[i].getStock() << "\n";
    }

    for (int i = 0; i < saleCount; i++)
    {
        saleFile << sales[i].getSaleId() << "|"
                 << sales[i].getAlbumId() << "|"
                 << sales[i].getCustomerId() << "|"
                 << sales[i].getQuantity() << "|"
                 << sales[i].getTotal() << "\n";
    }

    artistFile.close();
    customerFile.close();
    albumFile.close();
    saleFile.close();

    cout << "All records saved successfully.\n";
}

// =====================================================
// LOAD DATA FROM TEXT FILES
// =====================================================

void MusicStore::loadData()
{
    // Reset counts before loading.
    // This function should normally be called at startup.
    albumCount = 0;
    artistCount = 0;
    customerCount = 0;
    saleCount = 0;

    string line, field;

    ifstream artistFile("artists.txt");

    while (getline(artistFile, line))
    {
        stringstream ss(line);
        string name, genre;
        int id;

        if (!getline(ss, field, '|')) continue;
        try { id = stoi(field); } catch (...) { continue; }

        if (!getline(ss, name, '|')) continue;
        if (!getline(ss, genre)) continue;

        bool duplicate = false;

        for (int i = 0; i < artistCount; i++)
            if (artists[i].getId() == id) duplicate = true;

        if (duplicate || id <= 0) continue;

        if (artistCount == artistCapacity) resizeArtists();
        artists[artistCount++] = Artist(id, name, genre);
    }

    ifstream customerFile("customers.txt");

    while (getline(customerFile, line))
    {
        stringstream ss(line);
        string name, phone;
        int id;

        if (!getline(ss, field, '|')) continue;
        try { id = stoi(field); } catch (...) { continue; }

        if (!getline(ss, name, '|')) continue;
        if (!getline(ss, phone)) continue;

        bool duplicate = false;

        for (int i = 0; i < customerCount; i++)
            if (customers[i].getId() == id) duplicate = true;

        if (duplicate || id <= 0) continue;

        if (customerCount == customerCapacity) resizeCustomers();
        customers[customerCount++] = Customer(id, name, phone);
    }

    ifstream albumFile("albums.txt");

    while (getline(albumFile, line))
    {
        stringstream ss(line);
        string title;
        int id, artistId, stock;
        double price;

        if (!getline(ss, field, '|')) continue;
        try { id = stoi(field); } catch (...) { continue; }

        if (!getline(ss, title, '|')) continue;

        if (!getline(ss, field, '|')) continue;
        try { artistId = stoi(field); } catch (...) { continue; }

        if (!getline(ss, field, '|')) continue;
        try { price = stod(field); } catch (...) { continue; }

        if (!getline(ss, field)) continue;
        try { stock = stoi(field); } catch (...) { continue; }

        bool artistFound = false;
        bool duplicate = false;

        for (int i = 0; i < artistCount; i++)
            if (artists[i].getId() == artistId) artistFound = true;

        for (int i = 0; i < albumCount; i++)
            if (albums[i].getAlbumId() == id) duplicate = true;

        if (!artistFound || duplicate || id <= 0 ||
            price <= 0 || stock < 0)
            continue;

        if (albumCount == albumCapacity) resizeAlbums();
        albums[albumCount++] =
            Album(id, title, artistId, price, stock);
    }

    ifstream saleFile("sales.txt");

    while (getline(saleFile, line))
    {
        stringstream ss(line);
        int id, albumId, customerId, quantity;
        double total;

        if (!getline(ss, field, '|')) continue;
        try { id = stoi(field); } catch (...) { continue; }

        if (!getline(ss, field, '|')) continue;
        try { albumId = stoi(field); } catch (...) { continue; }

        if (!getline(ss, field, '|')) continue;
        try { customerId = stoi(field); } catch (...) { continue; }

        if (!getline(ss, field, '|')) continue;
        try { quantity = stoi(field); } catch (...) { continue; }

        if (!getline(ss, field)) continue;
        try { total = stod(field); } catch (...) { continue; }

        bool albumFound = false;
        bool customerFound = false;
        bool duplicate = false;

        for (int i = 0; i < albumCount; i++)
            if (albums[i].getAlbumId() == albumId) albumFound = true;

        for (int i = 0; i < customerCount; i++)
            if (customers[i].getId() == customerId) customerFound = true;

        for (int i = 0; i < saleCount; i++)
            if (sales[i].getSaleId() == id) duplicate = true;

        if (!albumFound || !customerFound || duplicate ||
            id <= 0 || quantity <= 0 || total < 0)
            continue;

        if (saleCount == saleCapacity) resizeSales();

        sales[saleCount++] =
            Sale(id, albumId, customerId, quantity, total);
    }

    cout << "Data loading completed.\n";
}