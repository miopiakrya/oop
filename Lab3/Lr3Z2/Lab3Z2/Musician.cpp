#include "Musician.h"

void Musician::setMusic(std::string music)
{
	this->music = music;
}

std::string Musician::getMusic()
{
	return music;
}

void Musician::setExp(int exp)
{
	this->exp = exp;
}

int Musician::getExp()
{
	return exp;
}

void Musician::setGrade(int grade)
{
	this->grade = grade;
}

int Musician::getGrade()
{
	return grade;
}

void Musician::visit()
{
	exp++;
	grade += grade * (rand() % 5 + 1);
}

void Musician::print()
{
	std::cout << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(8) << sex << " " << std::setw(20) << music << " " << std::setw(5) << exp << " " << std::setw(5) << grade << std::endl;
}