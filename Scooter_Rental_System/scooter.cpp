#include "scooter.h"


Scooter::Scooter() : id(0), location(""), status(0), battery_level(0), total_distance(0.0), last_usage_date("") {}

Scooter::Scooter(int id, const string& loc, int stat, int batt, double dist, const string& lud)
    : id(id), location(loc), status(stat), battery_level(batt), total_distance(dist), last_usage_date(lud) {
}

int Scooter::getId() const { return id; }
string Scooter::getLocation() const { return location; }
int Scooter::getStatus() const { return status; }
int Scooter::getBatteryLevel() const { return battery_level; }
double Scooter::getTotalDistance() const { return total_distance; }
string Scooter::getLastUsageDate() const { return last_usage_date; }

void Scooter::setId(int id) { this->id = id; }
void Scooter::setLocation(const string& loc) { location = loc; }
void Scooter::setStatus(int stat) { status = stat; }
void Scooter::setBatteryLevel(int batt) { battery_level = batt; }
void Scooter::setTotalDistance(double dist) { total_distance = dist; }
void Scooter::setLastUsageDate(const string& lud) { last_usage_date = lud; }

void Scooter::saveToFile(ofstream& file) const {
    file << id << "," << location << "," << status << "," << battery_level << "," << total_distance << "," << last_usage_date << endl;
}

Scooter Scooter::loadFromFile(ifstream& file) {
    int id, status, battery_level;
    double total_distance;
    string location, last_usage_date;

    if (file >> id >> location >> status >> battery_level >> total_distance >> last_usage_date) {
        return Scooter(id, location, status, battery_level, total_distance, last_usage_date);
    }
    return Scooter(); 
}

void Scooter::updateDetails() {
    cout << "Updating scooter details..." << endl;
    
}

void Scooter::displayInfo() const {
    cout << "Scooter ID: " << id << endl;
    cout << "Location: " << location << endl;
    cout << "Status: " << (status == 1 ? "Available" : status == 2 ? "In Use" : "Unavailable") << endl; // ? if demek, : else demek 
    cout << "Battery Level: " << battery_level << "%" << endl;
    cout << "Total Distance: " << total_distance << " km" << endl;
    cout << "Last Usage Date: " << last_usage_date << endl;
}
