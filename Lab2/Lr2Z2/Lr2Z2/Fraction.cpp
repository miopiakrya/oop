#include "Fraction.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>

using namespace std;

Fraction::Fraction() {}
Fraction::Fraction(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Fraction::gcd(int n, int m)
{
    if (n % m == 0)
        return m;
    if (m % n == 0)
        return n;

    if (n > m)
        return gcd(n % m, m);
    return gcd(n, m % n);
}

void Fraction::reduce(int x, int y)
{
    int gcdD = gcd(x, y);

    x /= gcdD;
    y /= gcdD;

    cout << x << "\\" << y << endl;
}

void Fraction::printAsFraction(double decimal_fraction)
{
    stringstream ss;
    ss << setprecision(15) << decimal_fraction;
    string strNum = ss.str();
    size_t pos = strNum.find('.');

    decimal_fraction *= pow(10, strNum.size() - 1 - pos);
    int decimal = (int)decimal_fraction;
    int undecimal = pow(10, strNum.size() - 1 - pos);

    reduce(decimal, undecimal);
}

int Fraction::returnNumb()
{
    return numb;
}

void Fraction::setNumb(int numb)
{
    this->numb = numb;
}

void Fraction::printAsFraction(const char* decimal_fraction)
{
    numb++;
    stringstream ss;
    ss << setprecision(15) << decimal_fraction;
    string strNum = ss.str();
    size_t pos = strNum.find('.');

    int decimal = stof(decimal_fraction) * pow(10, strNum.size() - 1 - pos);
    int undecimal = pow(10, strNum.size() - 1 - pos);

    reduce(decimal, undecimal);
}

void Fraction::check() const
{
    if (y == 0)
    {
        throw overflow_error("Знаменатель - 0!");
    }
}

Fraction& Fraction::operator+(const Fraction& rhs) const
{
    int a = rhs.x, b = rhs.y;
    Fraction fract(x * b + y * a, y * b);
    return fract;
}
Fraction& Fraction::operator-(const Fraction& rhs) const
{
    int a = rhs.x, b = rhs.y;
    Fraction fract(x * b - y * a, y * b);
    return fract;
}
Fraction& Fraction::operator*(const Fraction& rhs) const
{
    int a = rhs.x, b = rhs.y;
    Fraction fract(x * a, y * b);
    return fract;
}
Fraction& Fraction::operator/(const Fraction& rhs) const
{
    int a = rhs.x, b = rhs.y;
    Fraction fract(x * b, y * a);
    return fract;
}