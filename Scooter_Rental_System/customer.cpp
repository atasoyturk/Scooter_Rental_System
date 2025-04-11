#include "Customer.h"

Customer::Customer() : id(0), name_surname(""), telephone(""), email(""), address("") {}
Customer::Customer(int id, const string& n_s, const string& num, const string& mail, const string& adr) : id(id), name_surname(n_s), telephone(num), email(mail), address(adr) {}

int Customer::getId() const { return id; }
string Customer::getNameSurname() const { return name_surname; }
string Customer::getTelephone() const { return telephone; }
string Customer::getEmail() const { return email; }
string Customer::getAddress() const { return address; }

void Customer::setId(int newId) { id = newId; }
void Customer::setNameSurname(const string& n_s) { name_surname = n_s; }
void Customer::setTelephone(const string& num) { telephone = num; }
void Customer::setEmail(const string& mail) { email = mail; }
void Customer::setAddress(const string& adr) { address = adr; }

void Customer::updateDetails() {
    cout << "Enter new details (leave blank):\n";
    string input;

    cout << "Name Surname [" << name_surname << "]: ";
    getline(cin, input);
    if (!input.empty()) name_surname = input;

    cout << "Telephone [" << telephone << "]: ";
    getline(cin, input);
    if (!input.empty()) telephone = input;

    cout << "Email [" << email << "]: ";
    getline(cin, input);
    if (!input.empty()) email = input;

    cout << "Address [" << address << "]: ";
    getline(cin, input);
    if (!input.empty()) address = input;
}

void Customer::saveToFile(ofstream& file) const {
    file << id << "\n" << name_surname << "\n" << telephone << "\n" << email << "\n" << address << "\n";
}

Customer Customer::loadFromFile(ifstream& file) {
    int id; string name, phone, email, addr;
    file >> id;
    file.ignore();
    getline(file, name); 
    getline(file, phone);
    getline(file, email);
    getline(file, addr);
    
    return Customer(id, name, phone, email, addr);
}