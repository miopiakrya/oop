#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction fraction;
    Fraction fractionA(1, 4);
    Fraction fractionB(2, 5);

    cout << "0.128 as rational fraction: ";
    fraction.printAsFraction(0.128);

    cout << "4.25 as rational fraction: ";
    fraction.printAsFraction("4.25");

    fraction = fractionA + fractionB;
    cout << endl << "1\\4 + 2\\5 = " << fraction << endl;

    fraction = fractionA - fractionB;
    cout << "1\\4 - 2\\5 = " << fraction << endl; 

    fraction = fractionA * fractionB;
    cout << "1\\4 * 2\\5 = " << fraction << endl;

    fraction = fractionA / fractionB;
    cout << "1\\4 / 2\\5 = " << fraction << endl << endl;

    cout << "reducing 128\\18: ";
    fraction.reduce(128, 18);

    cout << endl << "enter rational fraction: ";
    cin >> fraction;
}


