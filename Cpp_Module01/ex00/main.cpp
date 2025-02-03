#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie = newZombie("Undead");
	zombie->announce();
	randomChump("Champ");
	delete zombie;
}