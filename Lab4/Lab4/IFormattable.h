#pragma once
#include <string>

class IFormattable
{
	virtual std::string format() {};
	
	virtual void prettyPrint(const IFormattable& object) {};
};

