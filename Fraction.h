//Guoqin Sun
//914785301


#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
public:
    Fraction();
    friend std::istream& operator >> (std::istream& i,Fraction& f);
    friend std::ostream& operator << (std::ostream& o,Fraction& f);
    Fraction(int num, int den);
    int getNum() const;
    int getDen() const;
    friend const Fraction operator+(const Fraction& x, const Fraction& y);
    friend const Fraction operator-(const Fraction& x, const Fraction& y);
    int find_gcd (int n1, int n2);

private:
    int n;
    int d;
};


#endif
