#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
    arr = new double* [columns];
    for (int i = 0; i < 4; i++)
        *(arr + i) = new double[rows];
}

Matrix::~Matrix()
{
    for (int i = 0; i < 4; i++)
        delete[] arr[i];
    delete[] arr;
}

double Matrix::at(int i, int j) const
{
    return *(*(arr + j) + i);
}

void Matrix::setAt(int i, int j, double val)
{
    *(*(arr + j) + i) = val;
}

double** Matrix::getArr()
{
    return arr;
}

Matrix& Matrix::operator++()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ++(*(*(arr + j) + i));
    return *this;
}

Matrix& Matrix::operator--()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            --(*(*(arr + j) + i));
    return *this;
}

double** Matrix::operator++(int)
{
    double** oldArr = arr;
    ++* this;
    return oldArr;
}

double** Matrix::operator--(int)
{
    double** oldArr = arr;
    --* this;
    return oldArr;
}