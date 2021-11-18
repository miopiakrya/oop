#include "Game.h"
#include <ctime>
#include <random>

Game::Game(int startingPlayerCash) 
{
    std::cout << "� ��� " << startingPlayerCash << std::endl;
    user = Player();

    user.totalCash = startingPlayerCash;
    dealer = Player();
}

void Game::showInfo() 
{
    printf("������: [%u] [%u] [%u] [%u]\n", decks[0].getCardsLeft(), decks[1].getCardsLeft(), decks[2].getCardsLeft(), decks[3].getCardsLeft());

    std::cout << "�����: " << dealer.hand << std::endl;
    std::cout << "��: " << user.hand << std::endl;
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

    std::cout << "1. ������" << std::endl;
    std::cout << "2. ���" << std::endl;
    if (!isTripled)
    {
        std::cout << "3. �����" << std::endl;
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
            std::cout << "�������� ��������" << std::endl;
        }

        break;
    default:
        std::cout << "�������� ��������" << std::endl;
        prompt();
    }
}

void Game::startGame(size_t _bet)
{
    if (user.totalCash < _bet) 
    {
        throw std::out_of_range("�� ������� �����");
    }

    bet = _bet;
    user.totalCash -= bet;

    addCardToPlayer();
    addCardToPlayer();
    addCardToDealer();
}

void Game::endGame() 
{
    std::cout << "���� ��������." << std::endl;

    addCardToDealer();
    size_t userScore = 0;
    bool userLost = false;

    try 
    {
        userScore = user.hand.getTotalValue();
    } catch (std::overflow_error)
    {
        std::cout << "� ��� ������ 21, � ������� �� ���������. �� �������� " << bet << "." << std::endl;
        std::cout << "� ��� " << user.totalCash << std::endl;

        user.hand.resetDeck();
        dealer.hand.resetDeck();

        isTripled = false;
        return;
    }

    size_t dealerScore = dealer.hand.getTotalValue();
    std::cout << "� ������ " << dealerScore << "." << std::endl;
    std::cout << "� ��� " << userScore << "." << std::endl;

    if (userScore == 21) 
    {
        std::cout << "� ��� 21 ����. �� ��������." << std::endl;

        if (user.hand.isBlackjack()) 
        {
            std::cout << "� ���� ��, � ��� ��� � ������������� ����� ����� �����. ��� ������� ������.. �� �������� " << bet * 2 << "." << std::endl;
        } else 
        {
            std::cout << "�� �������� " << bet << "." << std::endl;
        }
    } else if (dealerScore == 21) 
    {
        std::cout << "� ������ 21. �� ���������. �� �������� " << bet << "." << std::endl;
        userLost = true;
    } else 
    {
        std::cout << "�� � ���� �� ������ 21, �� ";
        if (userScore < 21 && userScore > dealerScore) 
        {
            std::cout << "�� ����� � 21, � ������� ��������. ��� ������� " << bet << "." << std::endl;
        } else 
        {
            std::cout << "����� ����� � 21, � ������� �� ���������. �� �������� " << bet << "." << std::endl;

            userLost = true;
        }
    }

    if (!userLost) 
    {
        user.totalCash = user.totalCash + bet * (!user.hand.isBlackjack() ? 2 : 4);
    }

    std::cout << "� ��� " << user.totalCash << std::endl;

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
        std::cout << "�� ������� ������� ��� ������." << std::endl;
    } 
}

size_t Game::getTotalCash() 
{
    return user.totalCash;
}
