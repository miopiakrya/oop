#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>

using namespace std;

class Fraction
{
private:
    int numb = 0, x, y;
public:
    Fraction()
    {

    }
    Fraction(int x, int y)
    {
        numb++;
        this->x = x;
        this->y = y;
    }

    int gcd(int n, int m)
    {
        if (n % m == 0)
            return m;
        if (m % n == 0)
            return n;

        if (n > m)
            return gcd(n % m, m);
        return gcd(n, m % n);
    }

    void reduce(int x, int y)
    {
        int gcdD = gcd(x, y);

        x /= gcdD;
        y /= gcdD;

        cout << x << "\\" << y << endl;
    }

    void printAsFraction(double decimal_fraction)
    {
        numb++;
        stringstream ss;
        ss << setprecision(15) << decimal_fraction;
        string strNum = ss.str();
        size_t pos = strNum.find('.');

        decimal_fraction *= pow(10, strNum.size() - 1 - pos);
        int decimal = (int)decimal_fraction;
        int undecimal = pow(10, strNum.size() - 1 - pos);

        reduce(decimal, undecimal);
    }

    void printAsFraction(const char* decimal_fraction)
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

    void check() const
    {
        if (y == 0)
        {
            throw overflow_error("Знаменатель - 0!");
        }
    }

    Fraction& operator+(const Fraction& rhs) const
    {
        int a = rhs.x, b = rhs.y;
        Fraction fract(x * b + y * a, y * b);
        return fract;
    }
    Fraction& operator-(const Fraction& rhs) const
    {
        int a = rhs.x, b = rhs.y;
        Fraction fract(x * b - y * a, y * b);
        return fract;
    }
    Fraction& operator*(const Fraction& rhs) const
    {
        int a = rhs.x, b = rhs.y;
        Fraction fract(x * a, y * b);
        return fract;
    }
    Fraction& operator/(const Fraction& rhs) const
    {
        int a = rhs.x, b = rhs.y;
        Fraction fract(x * b, y * a);
        return fract;
    }

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



