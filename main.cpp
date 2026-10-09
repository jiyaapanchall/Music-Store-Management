
#include "MusicStore.h"

#include <iostream>
#include <limits>

using namespace std;

// Reads a valid integer menu choice.
int readChoice()
{
    int choice;

    while (true)
    {
        cout << "Enter your choice: ";

        if (cin >> choice)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Add-record submenu
void addMenu(MusicStore& store)
{
    cout << "\n--- Add Record ---\n";
    cout << "1. Add Artist\n";
    cout << "2. Add Customer\n";
    cout << "3. Add Album\n";

    int choice = readChoice();

    switch (choice)
    {
        case 1:
            store.addArtist();
            break;

        case 2:
            store.addCustomer();
            break;

        case 3:
            store.addAlbum();
            break;

        default:
            cout << "Invalid choice!\n";
    }
}

// Display-record submenu
void displayMenu(const MusicStore& store)
{
    cout << "\n--- Display Records ---\n";
    cout << "1. Display Artists\n";
    cout << "2. Display Customers\n";
    cout << "3. Display Albums\n";
    cout << "4. Display Sales\n";

    int choice = readChoice();

    switch (choice)
    {
        case 1:
            store.displayArtists();
            break;

        case 2:
            store.displayCustomers();
            break;

        case 3:
            store.displayAlbums();
            break;

        case 4:
            store.displaySales();
            break;

        default:
            cout << "Invalid choice!\n";
    }
}

// Search-record submenu
void searchMenu(const MusicStore& store)
{
    cout << "\n--- Search Record ---\n";
    cout << "1. Search Artist\n";
    cout << "2. Search Customer\n";
    cout << "3. Search Album\n";

    int choice = readChoice();

    switch (choice)
    {
        case 1:
            store.searchArtist();
            break;

        case 2:
            store.searchCustomer();
            break;

        case 3:
            store.searchAlbum();
            break;

        default:
            cout << "Invalid choice!\n";
    }
}

// Update-record submenu
void updateMenu(MusicStore& store)
{
    cout << "\n--- Update Record ---\n";
    cout << "1. Update Artist\n";
    cout << "2. Update Customer\n";
    cout << "3. Update Album\n";

    int choice = readChoice();

    switch (choice)
    {
        case 1:
            store.updateArtist();
            break;

        case 2:
            store.updateCustomer();
            break;

        case 3:
            store.updateAlbum();
            break;

        default:
            cout << "Invalid choice!\n";
    }
}

// Delete-record submenu
void deleteMenu(MusicStore& store)
{
    cout << "\n--- Delete Record ---\n";
    cout << "1. Delete Artist\n";
    cout << "2. Delete Customer\n";
    cout << "3. Delete Album\n";

    int choice = readChoice();

    switch (choice)
    {
        case 1:
            store.deleteArtist();
            break;

        case 2:
            store.deleteCustomer();
            break;

        case 3:
            store.deleteAlbum();
            break;

        default:
            cout << "Invalid choice!\n";
    }
}

// Save/load submenu
void saveLoadMenu(MusicStore& store)
{
    cout << "\n--- Save / Load ---\n";
    cout << "1. Save Data\n";
    cout << "2. Load Data\n";

    int choice = readChoice();

    switch (choice)
    {
        case 1:
            store.saveData();
            break;

        case 2:
            store.loadData();
            break;

        default:
            cout << "Invalid choice!\n";
    }
}

int main()
{
    MusicStore store;

    cout << "====================================\n";
    cout << "     MUSIC STORE MANAGEMENT\n";
    cout << "====================================\n";

    // Load previously saved records when the program starts.
    store.loadData();

    int choice;

    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Update Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Main Transaction / Process\n";
        cout << "7. Report\n";
        cout << "8. Save / Load\n";
        cout << "9. Exit\n";
        cout << "===============================\n";

        choice = readChoice();

        switch (choice)
        {
            case 1:
                addMenu(store);
                break;

            case 2:
                displayMenu(store);
                break;

            case 3:
                searchMenu(store);
                break;

            case 4:
                updateMenu(store);
                break;

            case 5:
                deleteMenu(store);
                break;

            case 6:
                store.sellAlbum();
                break;

            case 7:
                store.showReport();
                break;

            case 8:
                saveLoadMenu(store);
                break;

            case 9:
                store.saveData();
                cout << "Data saved. Thank you for using "
                     << "Music Store Management!\n";
                break;

            default:
                cout << "Invalid choice! Please choose from 1 to 9.\n";
        }

    } while (choice != 9);

    return 0;
}