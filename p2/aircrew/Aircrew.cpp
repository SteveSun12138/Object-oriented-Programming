//Guoqin Sun
//914785301
#include <iostream>
#include "Aircrew.h"
using namespace std;

//implements of Aircrew
Aircrew::Aircrew(std::string name_str):nm(name_str){}

Aircrew::~Aircrew(void) {}

const double Aircrew::maxHours() const {
    return 60;
}

const std::string Aircrew::name() const {
    return nm;
}

void Aircrew::setFlights(int i) {
    flightsTaken = i;
}

void Aircrew::setHours(double h) {
    hoursWorked = h;
}

void Aircrew::print() const {
    cout << type() << ": " << nm << " has operated "
    << flightsTaken << " flights for a total of " <<
    hoursWorked << " hours this week" << endl;

    cout << "Available flights: " << maxFlights() - flightsTaken << endl;
    cout << "Available hours: " << maxHours() - hoursWorked << endl;
}

void Aircrew::scheduleFlight(int f, double h) const {
    cout << "Attempting to schedule for "
    << f << " stop(s) " << h << " hours flight..." << endl;

    int flightsLeft = maxFlights() - flightsTaken;
    double hoursLeft = maxHours() - hoursWorked;
    if ((hoursLeft >= h) && (flightsLeft >= f + 1)){
        cout << "This crew member can be scheduled" << endl;
    }else{
        cout << "This crew member should be replaced" << endl;
    }
}

Aircrew* Aircrew::makeAircrew(char ch, string name_str) {
    if (ch == 'P') {
        return new Pilot(name_str);
    }else if (ch == 'A'){
        return new Attendant(name_str);
    }else if(ch == 'T'){
        return new TaggedAttendant(name_str);
    }

}

//implement of Pilot
Pilot::Pilot(string name_str) : Aircrew::Aircrew(name_str) {}

const string Pilot::type() const {
    return "Pilot";
}

const int Pilot::maxFlights() const {
    return 5;
}

//implement of Attendant
Attendant::Attendant(string name_str) : Aircrew::Aircrew(name_str){}

const std::string Attendant::type() const {
    return "Attendant";
}

const int Attendant::maxFlights() const {
    return 8;
}

//implement of TaggedAttendant
TaggedAttendant::TaggedAttendant(string name_str) : Aircrew::Aircrew(name_str) {}

const string TaggedAttendant::type() const {
    return "TaggedAttendant";
}

const int TaggedAttendant::maxFlights() const {
    return 8;
}

void TaggedAttendant::scheduleFlight(int f, double h) const {
    cout << "Attempting to schedule for "<< f
    << " stop(s) " << h << " hours flight..." << endl;

    int flightsLeft = maxFlights() - flightsTaken;
    double hoursLeft = maxHours() - hoursWorked;

    if ((hoursLeft >= h/2) && (flightsLeft >= f + 1)){
        cout << "This crew member can be scheduled" << endl;
    }else {
        cout<<"This crew member should be replaced"<<endl;
    }

}
