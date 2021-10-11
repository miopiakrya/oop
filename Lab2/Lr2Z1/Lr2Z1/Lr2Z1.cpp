#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

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

    //постфикс инкремент

    matrix++;
    cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << setprecision(3) << setw(4) << matrix.at(i, j) << " ";
        cout << '\n';
    }

    //постфикс декремент

    matrix--;
    cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << setprecision(3) << setw(4) << matrix.at(i, j) << " ";
        cout << '\n';
    }

    //переделываем 2-мерный в 1-мерный

    Vector vector(16);
    cout << "\n";

    vector.setArr(matrix.getArr());

    for (int i = 0; i < 16; i++)
        cout << vector[i] << " ";

    //проделываем то же самое с вектором

    cout << "\n";
    ++vector;

    for (int i = 0; i < 16; i++)
        cout << vector[i] << " ";

    cout << "\n";
    --vector;

    for (int i = 0; i < 16; i++)
        cout << vector[i] << " ";

    cout << "\n";
    vector++;

    for (int i = 0; i < 16; i++)
        cout << vector[i] << " ";

    cout << "\n";
    vector--;

    for (int i = 0; i < 16; i++)
        cout << vector[i] << " ";
}