#pragma once
#include "ILoggable.h"
#include "IShuffle.h"

class ExpressionEvaluator : public ILoggable, public IShuffle
{
protected:
	double* arr;
	int n;
public:
	virtual double calculate() = 0;

	ExpressionEvaluator();

	ExpressionEvaluator(int n);

	virtual ~ExpressionEvaluator();

	void setOperand(size_t pos, double value);

	void setOperands(double ops[], size_t n);
};

