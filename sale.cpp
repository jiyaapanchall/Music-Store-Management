
#include "Sale.h"

// Default constructor
Sale::Sale()
{
    saleId = 0;
    albumId = 0;
    customerId = 0;
    quantity = 0;
    total = 0.0;
}

// Parameterized constructor
Sale::Sale(int saleId, int albumId, int customerId,
           int quantity, double total)
{
    this->saleId = saleId;
    this->albumId = albumId;
    this->customerId = customerId;
    this->quantity = quantity;
    this->total = total;
}

// Destructor
Sale::~Sale()
{
}

// Calculate total amount
double Sale::calculateTotal(double price)
{
    total = price * quantity;
    return total;
}

// Display sale details
void Sale::display() const
{
    cout << "\n--- Sale Details ---" << endl;
    cout << "Sale ID: " << saleId << endl;
    cout << "Album ID: " << albumId << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Amount: " << total << endl;
}

// Getters
int Sale::getSaleId() const
{
    return saleId;
}

int Sale::getAlbumId() const
{
    return albumId;
}

int Sale::getCustomerId() const
{
    return customerId;
}

int Sale::getQuantity() const
{
    return quantity;
}

double Sale::getTotal() const
{
    return total;
}

// Setters
void Sale::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Sale::setTotal(double total)
{
    this->total = total;
}