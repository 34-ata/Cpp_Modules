#include "Zombie.hpp"

int	main(void)
{
	int	count = 20;
	Zombie* horde = zombieHorde(count, "Name");
	for (int i = 0; i < count; i++)
		horde[i].announce();
	delete[] horde;
}