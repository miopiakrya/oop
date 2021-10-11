#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Fraction
{
private:
    int numb;
    int x, y;
public:
    Fraction();
    Fraction(int x, int y);

    int gcd(int n, int m);

    void reduce(int x, int y);

    void printAsFraction(double decimal_fraction);

    int returnNumb();

    void setNumb(int numb);

    void printAsFraction(const char* decimal_fraction);

    void check() const;

    Fraction& operator+(const Fraction& rhs) const;
    Fraction& operator-(const Fraction& rhs) const;
    Fraction& operator*(const Fraction& rhs) const;
    Fraction& operator/(const Fraction& rhs) const;

    friend istream& operator>>(std::istream& ist, Fraction& value)
    {
        ist >> value.x >> value.y;
        value.check();
        value.reduce(value.x, value.y);
        return ist;
    }
    friend ostream& operator<<(std::ostream& ost, const Fraction& value)
    {
        ost << value.x << "\\" << value.y;
        return ost;
    }
};



