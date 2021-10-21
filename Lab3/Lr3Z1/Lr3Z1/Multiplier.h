#pragma once
#include "ExpressionEvaluator.h"
#include <fstream>
#include <iostream>

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier() : ExpressionEvaluator() {};

	Multiplier(int n) : ExpressionEvaluator(n) {};

	double calculate();

	void logToScreen();

	void logToFile(const std::string& filename);

	void shuffle();

	void shuffle(size_t i, size_t j);
};

