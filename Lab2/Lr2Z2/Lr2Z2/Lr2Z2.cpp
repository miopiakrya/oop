#include "Fraction.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int fractions = 0;
    Fraction fraction;
    fractions++;
    Fraction fractionA(1, 4);
    fractions++;
    Fraction fractionB(2, 5);
    fractions++;

    cout << "\n0.128 as rational fraction: ";
    fraction.printAsFraction(0.128);
    fractions++;

    cout << "4.25 as rational fraction: ";
    fraction.printAsFraction("4.25");
    fractions++;

    fraction = fractionA + fractionB;
    fractions++;
    cout << endl << "1\\4 + 2\\5 = " << fraction << endl;

    fraction = fractionA - fractionB;
    fractions++;
    cout << "1\\4 - 2\\5 = " << fraction << endl; 

    fraction = fractionA * fractionB;
    fractions++;
    cout << "1\\4 * 2\\5 = " << fraction << endl;

    fraction = fractionA / fractionB;
    fractions++;
    cout << "1\\4 / 2\\5 = " << fraction << endl << endl;

    cout << "reducing 128\\18: ";
    fraction.reduce(128, 18);
    fractions++;

    cout << endl << "enter rational fraction: ";
    cin >> fraction;
    fractions++;

    fraction.setNumb(fractions);
    cout << endl << "number of fractions: " << fraction.returnNumb();
}


