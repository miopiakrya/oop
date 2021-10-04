#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{  
private:
    double** arr;
public:
    Matrix(int rows, int columns)
    {
        arr = new double* [columns];
        for (int i = 0; i < 4; i++)
            *(arr + i) = new double[rows];
    }
    
    ~Matrix() 
    {
        delete[] arr;
    }

    double at(int i, int j) const
    {
        return *(*(arr + j) + i);
    }

    void setAt(int i, int j, double val) 
    {
        *(*(arr + j) + i) = val;
    }

    Matrix& operator++();
    Matrix& operator--();
};

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

class Vector
{
private:
    double* arr;
public:
    Vector(int elem)
    {
        arr = new double[elem];
    }

    void replace(int summ, double elem) 
    {
        *(arr + summ) = elem;
    }

    double& operator[] (const int index);
};

double& Vector::operator[] (const int index)
{
    return *(arr + index);  
}

int main()
{
    Matrix matrix(4, 4);
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix.setAt(i, j, sqrt(i + j + 1));

    //добавляем ко всему массиву 1

    ++matrix;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << setprecision(3) << setw(4) << matrix.at(i, j) << " ";
        cout << '\n';
    }

    //уменьшаем весь массив на 1

    --matrix;
    cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << setprecision(3) << setw(4) << matrix.at(i, j) << " ";
        cout << '\n';
    }

    //переделываем 2-мерный в 1-мерный

    Vector vector(16);
    int summ = 0;
    cout << "\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            vector.replace(summ, matrix.at(i, j));
            summ++;
        }
    }

    for (int i = 0; i < 16; i++)
        cout << vector[i] << " ";
} 