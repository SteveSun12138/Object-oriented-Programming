#include <iostream>
#include "Table.h"

using namespace std;

Table::Table(int n) : maxGuests(n), numGuests(0) {}

int Table::maxOccupancy() {
    return maxGuests;
}

int Table::currentOccupancy() {
    return numGuests;
}

bool Table::addGuests(int n) {
    if(n < (maxGuests - numGuests) || n == (maxGuests - numGuests)){
        numGuests += n;
        return true;
    }else{
        return false;
    }
}


