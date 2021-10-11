#include "Musician.h"

Musician::Musician() {};

Musician::Musician(std::string name, std::string surName, std::string dateOBirth, std::string music, int grade)
{
	this->name = name;
	this->surName = surName;
	this->dateOBirth = dateOBirth;
	this->music = music;
	this->grade = grade;
}

void Musician::setName(std::string name)
{
	this->name = name;
}

std::string Musician::getName()
{
	return name;
}

void Musician::setSurName(std::string surName)
{
	this->surName = surName;
}

std::string Musician::getSurName()
{
	return surName;
}

void Musician::setDateOBirth(std::string dateOBirth)
{
	this->dateOBirth = dateOBirth;
}

std::string Musician::getDateOBirth()
{
	return dateOBirth;
}

void Musician::setMusic(std::string music)
{
	this->music = music;
}

std::string Musician::getMusic()
{
	return music;
}

void Musician::setGrade(int grade)
{
	this->grade = grade;
}

int Musician::getGrade()
{
	return grade;
}

void Musician::print() const
{
	std::cout << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(20) << music << " " << std::setw(5) << grade << std::endl;
}
void Musician::serialize(const std::string& filename) const
{
	std::ofstream out;
	out.open(filename, std::ios::app);
	if (out.is_open())
	{
		out << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(20) << music << " " << std::setw(5) << grade << std::endl;
	}
	out.close();
}

void Musician::deserialize(const std::string& filename) const
{
	std::string line;
	std::ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}

void Musician::emptySerialize() const
{
	std::ofstream out;
	out.open(filename, std::ios::app);
	if (out.is_open())
	{
		out << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(20) << music << " " << std::setw(5) << grade << std::endl;
	}
	out.close();
}

void Musician::emptyDeserialize() const
{
	std::string line;
	std::ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}