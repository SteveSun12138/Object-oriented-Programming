//Guoqin Sun
//914785301

#include "Domain.h"
#include <iostream>
using namespace std;

Domain::Domain() {
    sizex = 600;
    sizey = 500;
}

Domain::~Domain() {

}

void Domain::addShape(const Shape *p) {
   s.push_back(p);
}

void Domain::draw() {

    cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
    cout << "<svg width=\"700\" height=\"600\"" << endl;
    cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl;
    cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
    cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl;


    Rectangle *domain = new Rectangle(Point(0, 0), sizex, sizey);

    for(int i = 0; i < s.size(); ++i) {
        s[i]->draw();
    }

    cout << "</g>" << endl;
    cout << "<g transform=\"matrix(1,0,0,1,50,590)\"\n"
            " font-family=\"Arial\" font-size=\"32\">" << endl;
    cout << "<text x=\"0\" y=\"0\">";


    int notfit = 0;
    int overlap = 0;

    for(int i = 0; i < s.size(); ++i){
        if(!s.at(i)->fits_in(*domain)){
            notfit++;
        }
    }

    for(int i = 0; i < s.size() - 1; ++i){
        if (s.at(i)->overlaps(*s.at(i+1))){
            overlap++;
        }
    }


    if(notfit > 0){
        cout << "does not fit";
    }else if(overlap > 0){
        cout << "overlap";
    }else{
        cout << "ok";
    }


    cout << "</text>" << endl;
    cout << "</g>" << endl;
    cout << "</svg>" << endl;

}
