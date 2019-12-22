//Guoqin Sun
//914785301

#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {

}

istream &operator >> (istream &i, Fraction &f) {
    char op;
    i >> f.n >> op >> f.d;

    if(f.d < 0){
        f.d = f.d * (-1);
        f.n = f.n * (-1);
    }else if (f.d == 0){
        throw invalid_argument("zero denominator");
    }

    return i;
}

ostream& operator << (ostream& o,Fraction& f){
    if(f.d != 1){
        o << f.n << '/' << f.d;
    }
    else{
        o << f.n;
    }

    return o;
}

Fraction::Fraction(int num, int den){
    n = num;
    d = den;

}

int Fraction::getNum() const{
    return n;
}

int Fraction::getDen() const{
    return d;
}

const Fraction operator+(const Fraction& x, const Fraction& y) {
    Fraction temp;
        int gcd = temp.find_gcd(x.d, y.d);
        temp.d = x.d * y.d/ gcd;
        temp.n = x.n * y.d / gcd + y.n * x.d / gcd;


    if(temp.n % temp.d == 0){
        temp.n = temp.n / temp.d;
        temp.d = 1;
    }

    return temp;
}

const Fraction operator-(const Fraction& x, const Fraction& y) {
    Fraction temp;
        int gcd = temp.find_gcd(x.d, y.d);
        temp.d = x.d * y.d / gcd;
        temp.n = x.n * y.d / gcd - y.n * x.d / gcd;

    if(temp.d < 0){
        temp.n = temp.n * (-1);
        temp.d = temp.d * (-1);
    }


    return temp;
}

/* find gcd of two numbers */
int Fraction::find_gcd (int n1, int n2)
{
    int gcd, remainder;

    /* Euclid's algorithm */
    remainder = n1 % n2;
    while ( remainder != 0 )
    {
        n1 = n2;
        n2 = remainder;
        remainder = n1 % n2;
    }
    gcd = n2;

    return gcd;
}
