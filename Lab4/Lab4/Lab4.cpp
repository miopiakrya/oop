// Уникальные правила: Одномастный блекджек; 
// Функция : Трипл;

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
        return "Перебор!";
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
        std::cout << "Ваша ставка?" << std::endl;

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
                std::cout << "У вас не осталось денег. Игра окончена." << std::endl;

                exit = 2;
                break;
            }
        }
        catch (std::out_of_range) 
        {
            std::cout << "У вас недостаточно денег!" << std::endl;
        }

        std::cout << "1. Продолжить" << std::endl;
        std::cout << "2. Выйти" << std::endl;

        std::cin >> exit;
    } while (exit != 2);
}

