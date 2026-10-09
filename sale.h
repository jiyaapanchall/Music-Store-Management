
#ifndef SALE_H
#define SALE_H

#include <iostream>
using namespace std;

class Sale
{
private:
    int saleId;
    int albumId;
    int customerId;
    int quantity;
    double total;

public:
    // Default constructor
    Sale();

    // Parameterized constructor
    Sale(int saleId, int albumId, int customerId,
         int quantity, double total);

    // Destructor
    ~Sale();

    // Calculate total amount
    double calculateTotal(double price);

    // Display sale details
    void display() const;

    // Getters
    int getSaleId() const;
    int getAlbumId() const;
    int getCustomerId() const;
    int getQuantity() const;
    double getTotal() const;

    // Setters
    void setQuantity(int quantity);
    void setTotal(double total);
};

#endif