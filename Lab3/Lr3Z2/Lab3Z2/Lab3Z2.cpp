// ��������� ��� ������� 3 ������������ �2, �������� ������ ������� � ��������. ����������� ����� 
// ������������ ������� � ��������� ������������ �� ������� ������. 
// ������� ��������� ���������� �������� IVisitor � ������� void visit(). ��� ��������� - ��������� ���� �� 1.
// ��� ������� - ������ ������ ��������� ����� (������ ���� �������� � �����; ��� �������������� ����� - ���������).
// � main() ������� 1 ��������� � 3 ��������.

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
