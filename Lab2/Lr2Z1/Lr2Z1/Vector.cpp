#include "Vector.h"

Vector::Vector(int elem)
{
    arr = new double[elem];
}

Vector::~Vector()
{
    delete[] arr;
}

void Vector::replace(int summ, double elem)
{
    *(arr + summ) = elem;
}

void Vector::setArr(double** elem)
{
    int summ = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            replace(summ, elem[i][j]);
            summ++;
        }
    }
}

double& Vector::operator[] (const int index)
{
    return *(arr + index);
}

Vector& Vector::operator++()
{
    for (int i = 0; i < 16; i++)
        ++* (arr + i);
    return *this;
}

Vector& Vector::operator--()
{
    for (int i = 0; i < 16; i++)
        --* (arr + i);
    return *this;
}

double* Vector::operator++(int)
{
    double* oldVector = arr;
    ++* this;
    return oldVector;
}

double* Vector::operator--(int)
{
    double* oldVector = arr;
    --* this;
    return oldVector;
}