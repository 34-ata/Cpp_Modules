#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
{
	this->name = name;
	std::cout << "Zombie " << name << " spawned." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " became un-undead." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
