#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Customer {
private:
    int id;
    string name_surname;
    string telephone;
    string email;
    string address;

public:
    Customer();
    Customer(int id, const string& n_s, const string& num, const string& mail, const string& adr);

    int getId() const;
    string getNameSurname() const;
    string getTelephone() const;
    string getEmail() const;
    string getAddress() const;

    void setId(int newId);
    void setNameSurname(const string& n_s);
    void setTelephone(const string& num);
    void setEmail(const string& mail);
    void setAddress(const string& adr);

    void updateDetails();
    void saveToFile(ofstream& file) const;
    static Customer loadFromFile(ifstream& file);
};
