#pragma once
#include <string>
#include "IVisitor.h"

class Human : public IVisitor
{
protected:
	std::string name, surName, sex, dateOBirth;
public: 
	Human();

	Human(std::string name, std::string surName, std::string dateOBirth, std::string sex);

	void setName(std::string name);
	std::string getName();

	void setSurName(std::string surName);
	std::string getSurName();

	void setDateOBirth(std::string dateOBirth);
	std::string getDateOBirth();

	void setSex(std::string sex);
	std::string getSex();
};

