//Guoqin Sun
//914785301

#include "Shape.h"
#include <iostream>
using namespace std;


bool Rectangle::overlaps(const Shape &r) const{
    return r.overlaps(*this);
}

bool Rectangle::overlaps(const Circle &r) const {
    int xn = min(max(r.center.x, position.x), position.x + width);
    int yn = min(max(r.center.y, position.y), position.y + height);
    Point d = Point(xn, yn) - Point(r.center.x, r.center.y);

    if(d.norm2() < (r.radius * r.radius)){
        return true;
    }else{
        return false;
    }

}

bool Rectangle::overlaps(const Rectangle &r) const {
    int dx = (2 * r.position.x + r.width) - (2 * position.x + width);
    int rx = width + r.width;


    int dy = (2 * r.position.y + r.height) - (2 * position.y - height);
    int ry = height + r.height;

    if(((dx * dx) < (rx * rx)) && ((dy * dy) < (ry * ry))){
        return true;
    }else{
        return false;
    }
}

bool Rectangle::fits_in(const Rectangle &r) const {
    if((r.position.x <= position.x) && ((position.x + width) <= (r.position.x + r.width))
    && (r.position.y <= position.y)
    && ((position.y + height) <= (r.position.y + r.height))){
        return true;
    }else{
        return false;
    }
}

void Rectangle::draw() const {

    cout << "<rect x=\"" << position.x << "\" y=\"" << position.y << "\" width=\"" <<
         width << "\" height=\"" << height << "\"/>" << endl;
}

Rectangle::~Rectangle() {

}

bool Circle::overlaps(const Shape &s) const {
    return s.overlaps(*this);
}

bool Circle::overlaps(const Circle &r) const {
    Point p1 = Point(r.center.x, r.center.y);
    Point p2 = Point(center.x, center.y);

    Point point = p1 - p2;

    if(point.norm2() < ((radius + r.radius) * (radius + r.radius))){
        return true;
    }else{
        return false;
    }
}

bool Circle::overlaps(const Rectangle &r) const {
    Circle c;
    c.center = center;
    c.radius = radius;
    return r.overlaps(c);
}

bool Circle::fits_in(const Rectangle &r) const {
    if((r.position.x <= (center.x - radius)) && ((center.x + radius) <= (r.position.x + r.width))
    && (r.position.y <= (center.y - radius)) && ((center.y + radius) <= (r.position.y + r.height))){
        return true;
    }else{
        return false;
    }
}

void Circle::draw() const {
    cout << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\"/>" << endl;
}

Circle::~Circle() {

}

