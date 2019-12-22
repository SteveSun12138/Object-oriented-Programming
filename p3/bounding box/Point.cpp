//Guoqin Sun
//914785301

#include "Point.h"
#include <iostream>
using namespace std;

Point Point::operator+(const Point &rhs) const{
    Point *point = new Point;
    point->x = x + rhs.x;
    point->y = y + rhs.y;
    return *point;
}

Point Point::operator-(const Point &rhs) const {
    Point *point = new Point;
    point->x = x - rhs.x;
    point->y = y - rhs.y;
    return *point;
}

ostream& operator<<(ostream& os, const Point& p){
    os << "(" <<  p.x << ", " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& p){
    is >> p.x >> p.y;
    return is;
}
