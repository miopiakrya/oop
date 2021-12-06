#include "Card.h"
#include <iostream>
#include <string>

Card::Card(std::string _face) 
{
    face = _face;

    if (isdigit(face[0])) 
    {
        size_t num = int(_face[0]) - int('0');
        value = num;
        if (num == 1) 
        {
            value = 10;
        }   
    } else if (face[0] != 'A') 
    {
        value = 10;
    } else 
    {
        value = 11;
    }
}

Card::Card(const Card& c2)
{
    value = c2.value;
    face = c2.face;
}

Card::Card() {}

std::ostream& operator<<(std::ostream& out, const Card& card) 
{
    out << card.face;

    return out;
}

size_t Card::getValue() const 
{
    return value;
}

std::string Card::getFace() const 
{
    return face;
}