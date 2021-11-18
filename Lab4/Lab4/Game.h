#pragma once
#include "Player.h"
#include "Deck.h"

class Game 
{
private:
    Deck decks[4];

    Player dealer;
    Player user;

    int bet;
public:
    Game(int startingPlayerCash);

    void startGame(size_t bet);
    void showInfo();

    void addCardToPlayer();
    void addCardToDealer();

    void prompt();

    void triple();

    void endGame();
    size_t getTotalCash();
};

