#include "Human.h"

Human::Human() {}

Human::Human(std::string name, std::string surName, std::string dateOBirth, std::string sex)
{
	this->name = name;
	this->surName = surName;
	this->dateOBirth = dateOBirth;
	this->sex = sex;
}

void Human::setName(std::string name)
{
	this->name = name;
}

std::string Human::getName()
{
	return name;
}

void Human::setSurName(std::string surName)
{
	this->surName = surName;
}

std::string Human::getSurName()
{
	return surName;
}

void Human::setDateOBirth(std::string dateOBirth)
{
	this->dateOBirth = dateOBirth;
}

std::string Human::getDateOBirth()
{
	return dateOBirth;
}

void Human::setSex(std::string sex)
{
	this->sex = sex;
}

std::string Human::getSex()
{
	return sex;
}