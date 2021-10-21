#include "Substractor.h"

double Substractor::calculate()
{
	double calc = arr[0];
	for (int i = 1; i < n; i++)
	{
		calc -= arr[i];
	}

	return calc;
}

void Substractor::logToScreen()
{
	int numb = n - 1;

	std::cout << "Total: " << numb << std::endl;
	std::cout << arr[0];
	for (int i = 1; i < n; i++)
	{
		std::cout << " - " << arr[i];
	}
	std::cout << std::endl << "Equals to " << Substractor::calculate() << std::endl;
}

void Substractor::logToFile(const std::string& filename)
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
			out << " - " << arr[i];
		}
		out << std::endl << "Equals to " << Substractor::calculate() << std::endl;
	}
	out.close();
}

void Substractor::shuffle()
{
	int firstIndex, secondIndex;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] != round(arr[i]))
		{
			firstIndex = i;
			break;
		}
	}

	for (int i = n - 1; i > 0; i++)
	{
		if (arr[i] != round(arr[i]))
		{
			secondIndex = i;
			break;
		}
	}

	std::swap(arr[firstIndex], arr[secondIndex]);
}

void Substractor::shuffle(size_t i, size_t j)
{
	int firstIndex, secondIndex;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] != round(arr[i]))
		{
			firstIndex = i;
			break;
		}
	}

	for (int i = n - 1; i > 0; i++)
	{
		if (arr[i] != round(arr[i]))
		{
			secondIndex = i;
			break;
		}
	}

	std::swap(arr[firstIndex], arr[secondIndex]);
}
