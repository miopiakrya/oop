#include <iostream>
#include <iomanip>  //библиотека для вывода сообщений с форматом каким-то
#include <locale>
#include <math.h> //библиотека которая подключает математические приколы

using namespace std;

void init(double** arr) { //double** arr - динамический двумерный масив
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            *(*(arr + i) + j) = sqrt(i + j + 1); //аналогично arr[i][j] = sqrt(i + j + 1), sqrt - ето квадратный корень. Тут мы пишем элементы массива.
        }
    }
}

void output(double** arr) {
    cout << "2D:" << endl; //вывод сообщения 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setprecision(3) << setw(4) << *(*(arr + i) + j) << " "; //вывод сообщения с форматом. setw(4) - это количество символов которые пишутся. если символов меньше то остальное - пробел. setprecision - количество знаков в цифре
        }
        cout << endl;
    }
}

double* transform(double** arr) {
    double* a = new double[16];
    int summ = 0; //summ - номер элемента по порядку 

    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            *(a + summ) = *(*(arr + i) + j); //a[summ] = arr[i][j]
            summ++;
        }
    }

    return a;
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    double** arr = new double* [4];
    for (int i = 0; i < 4; i++) {
        *(arr + i) = new double[4];
    }

    init(arr);
    output(arr);

    double* a = transform(arr);
    printf("\n1D:\n");
    for (int i = 0; i < 16; i++) {
        cout << setprecision(5) << *(a + i) << " ";
    }

    for (int i = 0; i < rsize_t(arr); i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] a;
} 