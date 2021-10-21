#include "Multiplier.h"

double Multiplier::calculate()
{
	double calc = 1;
	for (int i = 0; i < n; i++)
	{
		calc *= arr[i];
	}

	return calc;
}

void Multiplier::logToScreen()
{
	int numb = n - 1;

	std::cout << "Total: " << numb << std::endl;
	std::cout << arr[0];
	for (int i = 1; i < n; i++)
	{
		std::cout << " * " << arr[i];
	}
	std::cout << std::endl << "Equals to " << Multiplier::calculate() << std::endl;
}

void Multiplier::logToFile(const std::string& filename)
{
	int numb = n - 1;

	std::ofstream out;
	out.open(filename, std::ios::app);
	if (out.is_open())
	{
		out << "Total: " << numb << std::endl;
		out << arr[0];
		for (int i = 1; i < n; i++)
		{
			out << " * " << arr[i];
		}
		out << std::endl << "Equals to " << Multiplier::calculate() << std::endl << std::endl;
	}
	out.close();
}

void Multiplier::shuffle()
{
	std::cout << "Shuffle is not allowed" << std::endl;
}

void Multiplier::shuffle(size_t i, size_t j)
{
	std::cout << "Shuffle is not allowed" << std::endl;
}