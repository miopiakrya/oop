#pragma once
#include "Deck.h"

class Hand 
{
private:
    static const size_t maxCards = 12;

    size_t numOfAces = 0;
    size_t totalCards = 0;

    bool blackjack = false;

    Card deck[maxCards] = {};
public:
    Hand();
    virtual ~Hand();

    size_t getTotalValue();

    void addCard(const Card& card);

    void showDeck();

    void resetDeck();

    bool isBlackjack();

    friend std::ostream& operator<<(std::ostream& out, const Hand& hand);
};


