#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Scooter {
private:
    int id;
    string location;
    int status; 
    int battery_level; 
    double total_distance; 
    string last_usage_date;

public:
    
    Scooter();
    Scooter(int id, const string& loc, int stat, int batt, double dist, const string& lud);

    int getId() const;
    string getLocation() const;
    int getStatus() const;
    int getBatteryLevel() const;
    double getTotalDistance() const;
    string getLastUsageDate() const;

    void setId(int id);
    void setLocation(const string& loc);
    void setStatus(int stat);
    void setBatteryLevel(int batt);
    void setTotalDistance(double dist);
    void setLastUsageDate(const string& lud);

    void saveToFile(ofstream& file) const;
    static Scooter loadFromFile(ifstream& file);

    void updateDetails();
    void displayInfo() const;
};
