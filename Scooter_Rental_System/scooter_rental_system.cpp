#include "scooter_rental_system.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

 Scooter* findScooterInList(LinkedList<Scooter>& list, int scooterId) {
    for (int i = 0; i < list.size(); i++) {
        if (list.get(i).getId() == scooterId) {
            return &list.get(i);
        }
    }
    return nullptr;
}

 Customer* findCustomerInList(LinkedList<Customer>& list, int customerId) {
    for (int i = 0; i < list.size(); i++) {
        if (list.get(i).getId() == customerId) {
            return &list.get(i);
        }
    }
    return nullptr;
}

void ScooterRentalSystem::addScooter(const Scooter& scooter) {
    scooters.add(scooter);
    cout << "Registering new scooter...\n";
    cout << "Scooter has been added successfully.\n";
}

void ScooterRentalSystem::listAvailableScooters() const {
    cout << "Available Scooters:\n";
    bool found = false;
    for (int i = 0; i < scooters.size(); i++) {
        Scooter s = scooters.get(i);
        if (s.getStatus() == 0) { 
            cout << "- Scooter " << s.getId()
                << ": Location: " << s.getLocation()
                << ", Status: Available"
                << ", Battery Level: " << s.getBatteryLevel() << "%"
                << ", Distance: " << s.getTotalDistance() << " km"
                << ", Last Usage: " << s.getLastUsageDate() << "\n"; 
            found = true;
        }
    }
    if (!found) cout << "No available scooters found.\n";
}

void ScooterRentalSystem::rentScooter(int scooterId, int customerId) {
    Scooter* scooter = nullptr;
    for (int i = 0; i < scooters.size(); i++) {
        if (scooters.get(i).getId() == scooterId) {
            scooter = &scooters.get(i);
            break;
        }
    }

    Customer* customer = nullptr;
    for (int i = 0; i < customers.size(); i++) {
        if (customers.get(i).getId() == customerId) {
            customer = &customers.get(i);
            break;
        }
    }

    if (!scooter || !customer) {
        cout << "Error: Invalid scooter or customer ID!\n";
        return;
    }

    if (scooter->getStatus() == 1) { 
        cout << "Error: Scooter " << scooterId << " is already rented!\n";
        return;
    }

    scooter->setStatus(1); 
    rentalHistory.add("Customer " + to_string(customerId) + " rented Scooter " + to_string(scooterId));

    cout << "Renting scooter " << scooterId << " to customer " << customerId << "...\n";
    cout << "Scooter " << scooterId << " has been rented to customer " << customerId << ".\n";
}

void ScooterRentalSystem::returnScooter(int scooterId) {
    Scooter* scooter = nullptr;
    for (int i = 0; i < scooters.size(); i++) {
        if (scooters.get(i).getId() == scooterId) {
            scooter = &scooters.get(i);
            break;
        }
    }

    if (!scooter) {
        cout << "Error: Scooter " << scooterId << " not found!\n";
        return;
    }

    if (scooter->getStatus() == 0) { 
        cout << "Error: Scooter " << scooterId << " is not currently rented!\n";
        return;
    }

    scooter->setStatus(0); 
    rentalHistory.add("Scooter " + to_string(scooterId) + " returned");

    cout << "Returning scooter " << scooterId << "...\n";
    cout << "Scooter " << scooterId << " has been returned and is now available.\n";
}

void ScooterRentalSystem::deleteScooter(int scooterId) {
    bool removed = false;
    for (int i = 0; i < scooters.size(); i++) {
        if (scooters.get(i).getId() == scooterId) {
            scooters.remove(i);
            removed = true;
            break;
        }
    }

    if (removed) {
        cout << "Deleting scooter " << scooterId << "...\n";
        cout << "Scooter " << scooterId << " has been deleted from the system.\n"; // PDF Sayfa 7
    }
    else {
        cout << "Error: Scooter not found!\n";
    }
}

void ScooterRentalSystem::updateScooter(int scooterId, int status, int battery_level,
    int distance, string last_usage_date) {
    Scooter* scooter = findScooterInList(scooters, scooterId);
    if (!scooter) {
        cout << "Error: Scooter not found!\n";
        return;
    }

    scooter->updateDetails();
    cout << "Updating scooter " << scooterId << "...\n";
    cout << "Scooter " << scooterId << "'s details have been updated successfully.\n"; // PDF Sayfa 7
}

// Customer operasyonlarý
void ScooterRentalSystem::registerCustomer(const Customer& customer) {
    customers.add(customer);
    cout << "Registering new customer...\n";
    cout << "Customer has been added successfully.\n"; 
}

void ScooterRentalSystem::deleteCustomer(int customerId) {
    bool removed = false;
    for (int i = 0; i < customers.size(); i++) {
        if (customers.get(i).getId() == customerId) {
            customers.remove(i);
            removed = true;
            break;
        }
    }

    if (removed) {
        cout << "Deleting customer " << customerId << "...\n";
        cout << "Customer " << customerId << " has been deleted from the system.\n"; 
    }
    else {
        cout << "Error: Customer not found!\n";
    }
}

void ScooterRentalSystem::updateCustomer(int customerId, string name_surname,
    string telephone, string email, string address) {
    Customer* customer = findCustomerInList(customers, customerId);
    if (!customer) {
        cout << "Error: Customer not found!\n";
        return;
    }

    customer->setNameSurname(name_surname);
    customer->setTelephone(telephone);
    customer->setEmail(email);
    customer->setAddress(address);

    cout << "Updating customer " << customerId << "...\n";
    cout << "Customer " << customerId << "'s details have been updated successfully.\n"; 
}

void ScooterRentalSystem::viewCustomerHistory(int customerId) const {
    cout << "Customer " << customerId << "'s Rental History:\n"; 
    bool found = false;

    for (int i = 0; i < rentalHistory.size(); i++) {
        string record = rentalHistory.get(i);
        if (record.find("Customer " + to_string(customerId))) {
            size_t pos = record.find("Scooter ");
            if (pos != string::npos) {
                int scooterId = stoi(record.substr(pos + 8));

                    Scooter* s = findScooterInList(const_cast<LinkedList<Scooter>&>(scooters), scooterId);
                    if (s) {
                        cout << "- Scooter " << s->getId()
                            << ", Location: " << s->getLocation()
                            << ", Status: " << (s->getStatus() == 0 ? "Available" : "Rented")
                            << ", Battery Level: " << s->getBatteryLevel() << "%\n"; 
                        found = true;
                    }
            }
        }
    }

    if (!found) {
        cout << "No rental history found for customer " << customerId << ".\n";
    }
}

void ScooterRentalSystem::loadFromFiles() {
    ifstream scooterFile("scooters.txt");
    
    if (scooterFile) {
        string line;
        while (getline(scooterFile, line)) {
            istringstream iss(line);
            int id, status, battery, distance;
            string location, date;
            if (iss >> id >> location >> status >> battery >> distance >> date) {
                scooters.add(Scooter(id, location, status, battery, distance, date));
            }
        }
    }

    ifstream customerFile("customers.txt");
    if (customerFile) {
        string line;
        while (getline(customerFile, line)) {
            istringstream iss(line);
            int id;
            string name, phone, email, address;
            if (iss >> id >> name >> phone >> email >> address) {
                customers.add(Customer(id, name, phone, email, address));
            }
        }
    }
}

void ScooterRentalSystem::saveToFiles() const {
    ofstream scooterFile("scooters.txt");
    for (int i = 0; i < scooters.size(); i++) {
        Scooter s = scooters.get(i);
        scooterFile << s.getId() << " "
            << s.getLocation() << " "
            << s.getStatus() << " "
            << s.getBatteryLevel() << " "
            << s.getTotalDistance() << " "
            << s.getLastUsageDate() << "\n";
    }

    ofstream customerFile("customers.txt");
    for (int i = 0; i < customers.size(); i++) {
        Customer c = customers.get(i);
        customerFile << c.getId() << " "
            << c.getNameSurname() << " "
            << c.getTelephone() << " "
            << c.getEmail() << " "
            << c.getAddress() << "\n";
    }
}