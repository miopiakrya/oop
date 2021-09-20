#include <iostream>
#include <iomanip>  
#include <locale>
#include <math.h> //библиотека которая подключает математические штуки


/*2D -> 1D. 4x4 в один ряд по элементам справа налево и сверху вниз 
заполнить массив числами x[i][j]=sqrt(i+j+1) 
каждый элемент одномерного массива вывести с точностью 4 знака после запятой ;  каждый элемент двумерного массива - с точностью 2 знака*/


using namespace std;

void init(double** arr)
{ 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            *(*(arr + i) + j) = sqrt(i + j + 1); //аналогично arr[i][j] = sqrt(i + j + 1)
        }
    }
}

void output(double** arr) 
{
    cout << "2D:" << endl; //вывод сообщения 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setprecision(3) << setw(4) << *(*(arr + i) + j) << " "; //вывод сообщения с форматом. setw(4) - количество символов которые пишутся. Если символов меньше то остальное - пробел. setprecision - количество знаков в цифре
        }
        cout << endl;
    }
}

void replace(double** arr) 
{
    double* a = new double[16];
    int summ = 0; //summ - номер элемента по порядку!! 

    printf("\n1D:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            *(a + summ) = *(*(arr + i) + j); //a[summ] = arr[i][j]
            summ++;
        }
    }

    for (int i = 0; i < 16; i++) {
        cout << setprecision(5) << *(a + i) << " ";
    }
}

int main(int argc, char** argv) 
{
    setlocale(LC_ALL, "Russian");
    double** arr = new double* [4];
    for (int i = 0; i < 4; i++) {
        *(arr + i) = new double[4];
    }

    init(arr);
    output(arr);
    replace(arr);
    for (int i = 0; i < rsize_t(arr); i++) {
        delete[] arr[i];
    }
    delete[] arr;

}