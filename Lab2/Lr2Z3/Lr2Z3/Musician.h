#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class Musician
{
private:
	std::string name, surName, dateOBirth, music;
	int grade;
public:
	Musician() {};
	Musician(std::string name, std::string surName, std::string dateOBirth, std::string music, int grade)
	{
		this->name = name;
		this->surName = surName;
		this->dateOBirth = dateOBirth;
		this->music = music;
		this->grade = grade;
	}

	void setName(std::string name)
	{
		this->name = name;
	}
	std::string getName()
	{
		return name;
	}
	void setSurName(std::string surName)
	{
		this->surName = surName;
	}
	std::string getSurName()
	{
		return surName;
	}
	void setDateOBirth(std::string dateOBirth)
	{
		this->dateOBirth = dateOBirth;
	}
	std::string getDateOBirth()
	{
		return dateOBirth;
	}
	void setMusic(std::string music)
	{
		this->music = music;
	}
	std::string getMusic()
	{
		return music;
	}
	void setGrade(int grade)
	{
		this->grade = grade;
	}
	int getGrade()
	{
		return grade;
	}
	void print() const
	{
		std::cout << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(20) << music << " " << std::setw(5) << grade << std::endl;
	}
	void serialize(const std::string& filename) const
	{
		std::ofstream out;
		out.open(filename, std::ios::app);
		if (out.is_open())
		{
			out << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(20) << music << " " << std::setw(5) << grade << std::endl;
		}
		out.close();
	}
	void deserialize(const std::string& filename) const
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
}; 

