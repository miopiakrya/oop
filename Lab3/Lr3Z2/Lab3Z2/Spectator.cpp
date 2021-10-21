#include "Spectator.h"

void Spectator::setPlaceInHall(std::string placeInHall)
{
	this->placeInHall = placeInHall;
}

std::string Spectator::getPlaceInHall()
{
	return placeInHall;
}

void Spectator::visit()
{
	std::string line, id;
	std::ifstream in(filename);
	std::ofstream out("D:\\Spectators\\newSpectators.txt");
	if (in.is_open())
	{
		getline(in, line);
		placeInHall = line;
		while (getline(in, line)) {
			out << line << std::endl;
		}
	}
	out.close();
	in.close();

	remove("D:\\Spectators\\Spectators.txt");
	rename("D:\\Spectators\\newSpectators.txt", "D:\\Spectators\\Spectators.txt");
}

void Spectator::print()	
{
	std::cout << std::setw(20) << name << " " << std::setw(20) << surName << " " << std::setw(8) << dateOBirth << " " << std::setw(8) << sex << " " << std::setw(20) << placeInHall << std::endl;
}