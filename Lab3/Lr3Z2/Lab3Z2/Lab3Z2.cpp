// Дополнить код задания 3 лабораторной №2, добавляя классы ЗРИТЕЛЬ и ЛИЧНОСТЬ. Реализовать схему 
// наследования классов и корректно распределить по классам данные. 
// Создать интерфейс посетителя концерта IVisitor с методом void visit(). Для музыканта - увеличить стаж на 1.
// Для зрителя - занять первое свободное место (список мест хранится в файле; при резервировании места - удаляется).
// В main() создать 1 музыканта и 3 зрителей.

#include <iostream>
#include <fstream>
#include "Musician.h"
#include "Spectator.h"
#include "IVisitor.h"

int main()
{
    std::ofstream out("D:\\Spectators\\Spectators.txt");
    if (out.is_open())
    {
        out << "There's 1 place" << std::endl;
        out << "There's 2 place" << std::endl;
        out << "There's no place" << std::endl;
    }
    out.close();

    Spectator spectator[3] =
    {
      Spectator("Alex", "Vazovskiy", "10/10/2000", "Male", "No place"),
      Spectator("Max", "Vazov", "09/03/1987", "Male", "No place"),
      Spectator("Tanya", "Vikushina", "08/05/2002", "Female", "No place") };
    Musician musicians = Musician("Oleg", "Skyrar", "10/11/1993", "Male", "Drums", 3, 64);

    std::cout << "There's Spectators:\n" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        spectator[i].visit();
        spectator[i].print();
    }

    std::cout << "\n\nThere's Musician:\n" << std::endl;
    musicians.visit();
    musicians.print();
}
