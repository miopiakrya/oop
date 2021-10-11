#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class Musician
{
private:
	std::string name, surName, dateOBirth, music, filename = "D:\\Musicians\\Musicians.txt";
	int grade;
public:
	Musician();
	Musician(std::string name, std::string surName, std::string dateOBirth, std::string music, int grade);

	void setName(std::string name);
	std::string getName();

	void setSurName(std::string surName);
	std::string getSurName();

	void setDateOBirth(std::string dateOBirth);
	std::string getDateOBirth();

	void setMusic(std::string music);
	std::string getMusic();

	void setGrade(int grade);
	int getGrade();

	void print() const;

	void serialize(const std::string& filename) const;
	void deserialize(const std::string& filename) const;

	void emptySerialize() const;
	void emptyDeserialize() const;
};

