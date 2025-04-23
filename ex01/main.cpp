#include "main.hpp"

int main()
{
	int	hord_size = 12;
	Zombie *horde = zombieHorde(hord_size, "Norbert le zombie");

	for (int i = 0; i < hord_size; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
