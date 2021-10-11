#pragma once

class Matrix
{
private:
    double** arr;
public:
    Matrix(int rows, int columns);
    ~Matrix();

    double at(int i, int j) const;
    void setAt(int i, int j, double val);

    double** getArr();

    Matrix& operator++();
    Matrix& operator--();

    double** operator++(int);
    double** operator--(int);
};
