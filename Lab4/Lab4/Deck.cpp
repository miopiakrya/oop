#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

std::string faces[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

Deck::Deck() 
{
    std::string cards[52];

    for (int i = 13; i < 26; i++) 
    {
        cards[i] = faces[i - 13] + char(4);
    }

    for (int i = 26; i < 39; i++) 
    {
        cards[i] = faces[i - 26] + char(5);
    }

    for (int i = 39; i < 52; i++) 
    {
        cards[i] = faces[i - 39] + char(6);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(std::begin(cards), std::end(cards), std::default_random_engine(seed));

    for (int i = 0; i < 52; i++) 
    {
        deck[i] = Card(cards[i]);
    }
}

Deck::~Deck() {}

Card Deck::getCardAt(size_t index) 
{
    return deck[index];
}

Card Deck::drawTopCard() 
{
    cardsLeft--;
    return deck[cardsLeft];
}

void Deck::showDeck()
{
    for (size_t i = 0; i < cardsLeft; i++)
    {
        std::cout << deck[i] << std::endl;
    }
}

size_t Deck::getCardsLeft() const 
{
    return cardsLeft;
}
