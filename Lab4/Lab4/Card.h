#pragma once
#include <string>
#include <iostream>

class Card 
{
private:
    std::string face;
    size_t value = 99;
public:
    Card();

    Card(std::string _face);

    Card(const Card& c2);

    size_t getValue() const;

    std::string getFace() const;

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};


