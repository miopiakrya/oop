#pragma once
#include <iostream>
#include <iomanip>
#include "Human.h"

class Musician : public Human
{
private:
	std::string music;
	int grade, exp;
public: 
	Musician(std::string name, std::string surName, std::string dateOBirth, std::string sex, 
		std::string music, int exp, int grade) 
		: Human(name, surName, dateOBirth, sex) 
	{
		this->music = music;
		this->exp = exp;
		this->grade = grade;
	};

	void setMusic(std::string music);
	std::string getMusic();

	void setExp(int exp);
	int getExp();

	void setGrade(int grade);
	int getGrade();

	void print();

	void visit();
};

