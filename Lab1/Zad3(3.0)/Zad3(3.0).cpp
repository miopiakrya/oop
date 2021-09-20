#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string.h>
#include <windows.h>
#pragma warning(disable : 4996)

/* формат char* strcat(char* dest, const char*, src)  Функция приписывает строку src к строке dest */

char* strcatm(char* dest, const char* src) { //dest - строка изначальная, scr - строка соединяемая
	int Lenghth = strlen(dest); // strlen - длина строки
	for (int i = 0; i < strlen(src); i++)
	*(dest + Lenghth + i) = *(src + i); // dest[Lenghth + 1] = scr[i]
	*(dest + Lenghth + strlen(src)) = '\0'; // \0 разделяющий знак
	return dest;
}


int main() {
	char dest[1000] = "zaschitayte ", src[1000] = " pozhaluysta "; // так как в прошлый раз введение строк сломало код в визуалке (дев++ рабочий), предлагаю самостоятельно ввести строки
	strcat(dest, src); 
	printf_s("%s\n", dest);
	strcatm(dest, src);
	printf_s("%s", dest);
}