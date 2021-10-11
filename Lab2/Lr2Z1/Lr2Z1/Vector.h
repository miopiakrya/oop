#pragma once

class Vector
{
private:
    double* arr;
public:
    Vector(int elem);
    ~Vector();

    void replace(int summ, double elem);
    void setArr(double** elem);

    double& operator[] (const int index);
    Vector& operator++();
    Vector& operator--();

    double* operator++(int);
    double* operator--(int);
};

