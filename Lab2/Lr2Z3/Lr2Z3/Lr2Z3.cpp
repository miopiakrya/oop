#include <iostream>
#include <locale>
#include "Musician.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    Musician musician[4];

    musician[0] = Musician("Пётр", "Чайковский", "07.08.1840", "фортепиано", 25);
 
    musician[1].setName("Виктор");
    musician[1].setSurName("Цой");
    musician[1].setDateOBirth("21.05.1962");
    musician[1].setMusic("гитара");
    musician[1].setGrade(10);

    musician[2].setName("Сергей");
    musician[2].setSurName("Щелкановцев");
    musician[2].setDateOBirth("13.03.1966");
    musician[2].setMusic("барабан");
    musician[2].setGrade(5);

    musician[3].setName("Никколо");
    musician[3].setSurName("Паганини");
    musician[3].setDateOBirth("27.11.1782");
    musician[3].setMusic("скрипка");
    musician[3].setGrade(3);

    for (int i = 0; i < 3; i++)
    {
        int saver = musician[i].getGrade();
        musician[i].setGrade(saver + saver * (rand() % 5 + 1));
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (musician[j].getGrade() < musician[j + 1].getGrade())
            {
                Musician muse = musician[j + 1];
                musician[j + 1] = musician[j];
                musician[j] = musician[j + 1];
            }
        }  
    }

    for (int i = 0; i < 4; i++)
    {
        musician[i].print();
    }

    musician[0].serialize("D:\\Musicians\\0.txt");
    musician[1].serialize("D:\\Musicians\\1.txt");
    musician[2].serialize("D:\\Musicians\\2.txt");
    musician[3].serialize("D:\\Musicians\\3.txt");

    std::cout << "Read from .TXT" << std::endl;
    musician[0].deserialize("D:\\Musicians\\0.txt");
    musician[1].deserialize("D:\\Musicians\\1.txt");
    musician[2].deserialize("D:\\Musicians\\2.txt");
    musician[3].deserialize("D:\\Musicians\\3.txt");
}

