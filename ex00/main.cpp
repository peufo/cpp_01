#include "main.hpp"

int main()
{
	Zombie *zombie;

	zombie = newZombie("Robert");
	zombie->announce();
	delete zombie;
	zombie = NULL;
	randomChump("Marco");
	randomChump("Louise");
	return 0;
}
