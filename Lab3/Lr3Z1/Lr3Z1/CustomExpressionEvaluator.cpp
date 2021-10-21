#include "CustomExpressionEvaluator.h"

double CustomExpressionEvaluator::calculate()
{
	double calc = arr[0] + arr[1];
	int i = 2;
	for (int i = 2; i < n; i++)
	{
		calc *= arr[i];
	}

	return calc;
}

void CustomExpressionEvaluator::logToScreen()
{
	int numb = n - 1;

	std::cout << "Total: " << numb << std::endl;
	std::cout << "( " << arr[0] << " + " << arr[1] << " )";
	for (int i = 2; i < n; i++)
	{
		std::cout << " * " << arr[i];
	}
	std::cout << std::endl << "Equals to " << CustomExpressionEvaluator::calculate() << std::endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	int numb = n - 1;

	std::ofstream out;
	out.open(filename, std::ios::app);
	if (out.is_open())
	{
		out << "Total: " << numb << std::endl;
		out << "( " << arr[0] << " + " << arr[1] << " )";
		for (int i = 2; i < n; i++)
		{
			out << " * " << arr[i];
		}
		out << std::endl << "Equals to " << CustomExpressionEvaluator::calculate() << std::endl << std::endl;
	}
	out.close();
}

void CustomExpressionEvaluator::shuffle()
{
	std::cout << "Shuffle is not allowed" << std::endl;
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
	std::cout << "Shuffle is not allowed" << std::endl;
}
