#include "Hand.h"

Hand::~Hand() {}

size_t Hand::getTotalValue() 
{
    if (totalCards == 2) 
    {
        Card c1 = deck[0];
        Card c2 = deck[1];

        if (c1.getFace()[1] == c2.getFace()[1]) 
        {
            if (numOfAces == 1 && (c1.getValue() == 10 || c2.getValue() == 10))
            {
                blackjack = true;
                return 21;
            }
        }
    }
    size_t totalValue = 0;
    for (size_t i = 0; i < totalCards; i++) 
    {
        size_t value = deck[i].getValue();
        if (value != 11) 
        {
            totalValue += value;
        }
        else 
        {
            totalValue += 1;
            numOfAces += 1;
        }
    }

    size_t i = 0;

    while (i != numOfAces) 
    {
        if (totalValue <= (21 - 10)) 
        {
            totalValue += 10;
        }

        i++;
    }

    if (totalValue > 21) throw std::overflow_error("More then 21!");
    return totalValue;
}

Hand::Hand() {}

void Hand::addCard(const Card& card) 
{
    if (totalCards == maxCards) 
    {
        std::cout << "Нельзя иметь больше " << maxCards << " карт в колоде!" << std::endl;
        return;
    }

    deck[totalCards] = card;
    totalCards++;
}

std::ostream& operator<<(std::ostream& out, const Hand& hand) 
{
    for (size_t i = 0; i < hand.totalCards; i++) 
    {
        out << hand.deck[i] << " ";
    }

    return out;
}
void Hand::showDeck() 
{
    for (size_t i = 0; i < totalCards; i++) 
    {
        std::cout << deck[i] << std::endl;
    }
}

bool Hand::isBlackjack() 
{
    return blackjack;
}

void Hand::resetDeck() 
{
    for (size_t i = 0; i < totalCards; i++) 
    {
        deck[i] = Card();
    }

    totalCards = 0;
}
