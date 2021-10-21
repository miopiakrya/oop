#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <iostream>
#include <fstream>

class Substractor : public ExpressionEvaluator
{
public: 
	Substractor() : ExpressionEvaluator() {};

	Substractor(int n) : ExpressionEvaluator(n) {};

	double calculate();

	void logToScreen();

	void logToFile(const std::string& filename);

	void shuffle();

	void shuffle(size_t i, size_t j);
};

