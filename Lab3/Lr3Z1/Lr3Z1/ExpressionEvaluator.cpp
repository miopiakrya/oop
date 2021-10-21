#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() 
{
	ExpressionEvaluator::arr = new double[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = 0;
	}
	n = 20;
}

ExpressionEvaluator::ExpressionEvaluator(int n)
{
	ExpressionEvaluator::arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	this->n = n;
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete[] arr;
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	ExpressionEvaluator::arr[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = ops[i];
	}
}
