#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "Human.h"

class Spectator : public Human
{
private:
	std::string placeInHall, filename = "D:\\Spectators\\Spectators.txt";
public:
	Spectator(std::string name, std::string surName, std::string dateOBirth, std::string sex, std::string placeInHall)
		: Human(name, surName, dateOBirth, sex)
	{
		this->placeInHall = placeInHall;
	};

	void setPlaceInHall(std::string placeInHall);
	std::string getPlaceInHall();

	void print();

	void visit();
};

