// ���������� �������: ����������� ��������; 
// ������� : �����;

#include <iostream>
#include <sstream>
#include <exception>
#include "Game.h"
#include "Hand.h"
#include "Deck.h"

struct TooMuchException : public std::exception
{
    const char* what() const throw ()
    {
        return "�������!";
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    int exit = 0;
    size_t startingPlayerCash = 10000;
    Game g = Game(startingPlayerCash);

    do 
    {
        std::cout << "���� ������?" << std::endl;

        size_t bet = 1;

        std::string betString;
        std::cin >> betString;

        std::stringstream sstream(betString);
        sstream >> bet;

        try 
        {
            g.startGame(bet);
            g.showInfo();
            g.prompt();

            if (g.getTotalCash() == 0) 
            {
                std::cout << "� ��� �� �������� �����. ���� ��������." << std::endl;

                exit = 2;
                break;
            }
        }
        catch (std::out_of_range) 
        {
            std::cout << "� ��� ������������ �����!" << std::endl;
        }

        std::cout << "1. ����������" << std::endl;
        std::cout << "2. �����" << std::endl;

        std::cin >> exit;
    } while (exit != 2);
}

