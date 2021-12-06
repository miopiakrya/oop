#include "Game.h"
#include <ctime>
#include <random>

Game::Game(int startingPlayerCash) 
{
    std::cout << "У вас " << startingPlayerCash << std::endl;
    user = Player();

    user.totalCash = startingPlayerCash;
    dealer = Player();
}

void Game::showInfo() 
{
    printf("Колоды: [%u] [%u] [%u] [%u]\n", decks[0].getCardsLeft(), decks[1].getCardsLeft(), decks[2].getCardsLeft(), decks[3].getCardsLeft());

    std::cout << "Дилер: " << dealer.hand << std::endl;
    std::cout << "Вы: " << user.hand << std::endl;
}

void Game::addCardToPlayer() 
{
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, 3);

    user.hand.addCard(decks[uid(gen)].drawTopCard());
}

void Game::addCardToDealer() 
{
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, 3);

    dealer.hand.addCard(decks[uid(gen)].drawTopCard());
}

bool isTripled = false;

void Game::prompt() 
{
    size_t userScore = 0;

    std::cout << "1. Хватит" << std::endl;
    std::cout << "2. Еще" << std::endl;
    if (!isTripled)
    {
        std::cout << "3. Трипл" << std::endl;
    }

    int action;
    std::cin >> action;

    switch (action)
    {
    case 1:
        showInfo();
        endGame();

        break;
    case 2:
        addCardToPlayer();
        showInfo();

        try
        {
            userScore = user.hand.getTotalValue();
            prompt();
        } catch (std::overflow_error)
        {
            endGame();
        }
        break;
    case 3:
        if (!isTripled)
        {
            isTripled = true;

            addCardToPlayer();
            triple();
            showInfo();

            try
            {
                userScore = user.hand.getTotalValue();
                prompt();
            }
            catch (std::overflow_error)
            {
                endGame();
            }
        } else
        {
            std::cout << "Неверное действие" << std::endl;
        }

        break;
    default:
        std::cout << "Неверное действие" << std::endl;
        prompt();
    }
}

void Game::startGame(size_t _bet)
{
    if (user.totalCash < _bet) 
    {
        throw std::out_of_range("Не хватает денег");
    }

    bet = _bet;
    user.totalCash -= bet;

    addCardToPlayer();
    addCardToPlayer();
    addCardToDealer();
}

void Game::endGame() 
{
    std::cout << "Игра окончена." << std::endl;

    addCardToDealer();
    size_t userScore = 0;
    bool userLost = false;

    try 
    {
        userScore = user.hand.getTotalValue();
    } catch (std::overflow_error)
    {
        std::cout << "У вас больше 21, и поэтому вы проиграли. Вы потеряли " << bet << "." << std::endl;
        std::cout << "У вас " << user.totalCash << std::endl;

        user.hand.resetDeck();
        dealer.hand.resetDeck();

        isTripled = false;
        return;
    }

    size_t dealerScore = dealer.hand.getTotalValue();
    std::cout << "У дилера " << dealerScore << "." << std::endl;
    std::cout << "У вас " << userScore << "." << std::endl;

    if (userScore == 21) 
    {
        std::cout << "У вас 21 очко. Вы победили." << std::endl;

        if (user.hand.isBlackjack()) 
        {
            std::cout << "К тому же, у вас туз и десятиочковая карта одной масти. Ваш выигрыш удвоен.. Вы выиграли " << bet * 2 << "." << std::endl;
        } else 
        {
            std::cout << "Вы получили " << bet << "." << std::endl;
        }
    } else if (dealerScore == 21) 
    {
        std::cout << "У дилера 21. Вы проиграли. Вы потеряли " << bet << "." << std::endl;
        userLost = true;
    } else 
    {
        std::cout << "Ни у кого не выпало 21, но ";
        if (userScore < 21 && userScore > dealerScore) 
        {
            std::cout << "Вы ближе к 21, и поэтому выиграли. Ваш выигрыш " << bet << "." << std::endl;
        } else 
        {
            std::cout << "Дилер ближе к 21, и поэтому вы проиграли. Вы потеряли " << bet << "." << std::endl;

            userLost = true;
        }
    }

    if (!userLost) 
    {
        user.totalCash = user.totalCash + bet * (!user.hand.isBlackjack() ? 2 : 4);
    }

    std::cout << "У вас " << user.totalCash << std::endl;

    isTripled = false;
    user.hand.resetDeck();
    dealer.hand.resetDeck();
}

void Game::triple() 
{
    if (user.totalCash > bet * 2) 
    {
        user.totalCash -= bet * 2;
        bet *= 3;
    } else
    {
        std::cout << "Не хватает средств для трипла." << std::endl;
    } 
}

size_t Game::getTotalCash() 
{
    return user.totalCash;
}
