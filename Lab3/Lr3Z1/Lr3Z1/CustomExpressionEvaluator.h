#pragma once
#include "ExpressionEvaluator.h"
#include <iostream>
#include <fstream>

class CustomExpressionEvaluator : public ExpressionEvaluator
{
public: 
	CustomExpressionEvaluator() : ExpressionEvaluator() {};

	CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {};

	double calculate();
	
	void logToScreen();

	void logToFile(const std::string& filename);

	void shuffle();

	void shuffle(size_t i, size_t j);
};

