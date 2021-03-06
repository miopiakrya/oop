#include <iostream> //библиотека шобы все работало
#include <cstdio>  //библиотека которую надо юзать по заданию
#include <locale>   //библиотека шобы на русском был ввод

// массив n=10, проинициализировать нулями., processArray() должна заполнить членами геом прогрессии с нач эл b1  и шагом q (ввести) , считать, вернуть cnt - количество всех трехзначных элементов массивы, а также 
// сформировать выходной массив (все элементы исходного, кроме тех которые делятся 3 с остатком 1. вывести на экран

void processArray(int arr[10]) {
    int b1, q, cnt = 0;  //b1 - первый элемент прогрессии, q - знаменатель прогрессии, cnt - то шо по условию нада.

    printf("Введите первый элемент массива: "); //вывод в библиотеке cstdio
    scanf_s("%d", &b1); //ввод в этой библиотеке
    arr[0] = b1;

    printf("Введите знаменатель геометрической прогрессии: ");
    scanf_s("%d", &q);

    for (int i = 1; i < 10; i++) { //цикл в котором считаем прогрессию
        arr[i] = arr[i - 1] * q;
    }

    for (int i = 0; i < 10; i++) { //цикл в котором считаем то что надо по заданию
        if (arr[i] / 100 > 0)
            cnt++;
        if (arr[i] % 3 != 1)
            printf("%d ", arr[i]);
    }

    printf("\ncnt = %d ", cnt);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    int arr[10];

    for (int i = 0; i < 10; i++) { //тоже по заданию
        arr[i] = 0;
    }

    processArray(arr);
}