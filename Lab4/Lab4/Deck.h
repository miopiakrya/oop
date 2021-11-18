#pragma once
#include "Card.h"
#include "IFormattable.h"

class Deck
{
private:
    Card deck[52] = {};
    size_t cardsLeft = 52;
public:
    Deck();
    virtual ~Deck();

    Card getCardAt(size_t index);

    Card drawTopCard();

    size_t getCardsLeft() const;

    void showDeck();
};

