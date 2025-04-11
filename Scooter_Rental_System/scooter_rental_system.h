#pragma once
#include "customer.h"
#include "scooter.h"
#include "LinkedList.h" 
#include <fstream>
#include <string>

using namespace std;

class ScooterRentalSystem {
private:
    LinkedList<Scooter> scooters;      
    LinkedList<Customer> customers;    
    LinkedList<string> rentalHistory;  
    Scooter* findScooterInList(LinkedList<Scooter>& list, int scooterId);
    Customer* findCustomerInList(LinkedList<Customer>& list, int customerId);



public:
    
    void addScooter(const Scooter& scooter);                          
    void listAvailableScooters() const;                               
    void rentScooter(int scooterId, int customerId);                 
    void returnScooter(int scooterId);                                
    void deleteScooter(int scooterId);                                
    void updateScooter(int scooterId, int status, int battery_level, int distance, string last_usage_date);

    void registerCustomer(const Customer& customer);                   
    void deleteCustomer(int customerId);                              
    void updateCustomer(int customerId, string name_surname, string telephone, string email,string address);
    void viewCustomerHistory(int customerId) const;                    

    void loadFromFiles();  
    void saveToFiles() const; 
};