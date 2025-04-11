#include <iostream>
#include "scooter_rental_system.h"
using namespace std;

void displayMenu() {
    cout << "\n-------------------------------------------\n";
    cout << "1. List Available Scooters\n";
    cout << "2. Rent a Scooter\n";
    cout << "3. Return a Scooter\n";
    cout << "4. View Customer Rental History\n";
    cout << "5. Register a New Scooter\n";
    cout << "6. Delete a Scooter\n";
    cout << "7. Update a Scooter\n";
    cout << "8. Register a New Customer\n";
    cout << "9. Delete a Customer\n";
    cout << "10. Update a Customer\n";
    cout << "11. Exit\n";
    cout << "-------------------------------------------\n";
}

void handleUserInput(ScooterRentalSystem& system) {
    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice (1-11): ";
        cin >> choice;

        switch (choice) {
        case 1: 
            system.listAvailableScooters();
            break;

        case 2: { 
            int scooterId, customerId;
            cout << "Enter Scooter ID and Customer ID : ";
            cin >> scooterId >> customerId;
            system.rentScooter(scooterId, customerId);
            break;
        }

        case 3: { 
            int scooterId;
            cout << "Enter Scooter ID to return : ";
            cin >> scooterId;
            cout << "Returning scooter " << scooterId << "...\n";
            system.returnScooter(scooterId);
            break;
        }

        case 4: { 
            int customerId;
            cout << "Enter Customer ID : ";
            cin >> customerId;
            cout << "Customer " << customerId << "'s Rental History:\n";
            system.viewCustomerHistory(customerId);
            break;
        }

        case 5: { 
            int battery, distance;
            string location, date;

            cout << "Enter Location : ";
            cin >> location;
            cout << "Enter Battery Level : ";
            cin >> battery;
            cout << "Enter Distance: ";
            cin >> distance;
            cout << "Enter Last Usage Date: ";
            cin >> date;

            static int lastScooterId = 0;
            system.addScooter(Scooter(++lastScooterId, location, 0, battery, distance, date));
            cout << "Registering new scooter...\n";
            cout << "Scooter has been added successfully.\n";
            break;
        }

        case 6: { 
            int scooterId;
            cout << "Enter Scooter ID to delete (e.g., 1): ";
            cin >> scooterId;
            cout << "Deleting scooter " << scooterId << "...\n";
            system.deleteScooter(scooterId);
            break;
        }

        case 7: { 
            int scooterId, battery, distance;
            string location;

            cout << "Enter Scooter ID to update : ";
            cin >> scooterId;
            cout << "Enter New Location : ";
            cin >> location;
            cout << "Enter New Battery Level: ";
            cin >> battery;
            cout << "Enter New Distance : ";
            cin >> distance;

            cout << "Updating scooter " << scooterId << "...\n";
            system.updateScooter(scooterId, 0, battery, distance, "2025-03-20");
            cout << "Scooter " << scooterId << "'s details have been updated successfully.\n";
            break;
        }

        case 8: { 
            string name, phone, email, address;

            cout << "Enter Name Surname : ";
            cin >> name;
            cout << "Enter Telephone : ";
            cin >> phone;
            cout << "Enter Email : ";
            cin >> email;
            cout << "Enter Address : ";
            cin >> address;

            static int lastCustomerId = 0;
            system.registerCustomer(Customer(++lastCustomerId, name, phone, email, address));
            cout << "Registering new customer...\n";
            cout << "Customer has been added successfully.\n";
            break;
        }

        case 11: // Exit
            system.saveToFiles();
            cout << "Exiting program. Goodbye!\n";
            return;

        default:
            cout << "Invalid choice! Please enter 1-11.\n";
        }
    }
}

int main() {
    ScooterRentalSystem system;
    system.loadFromFiles();

    handleUserInput(system);

    return 0;
}