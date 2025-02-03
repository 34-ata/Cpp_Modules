#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& new_weapon)
{
	this->weapon = &new_weapon;
}

void HumanB::attack() const
{
	if (weapon == NULL)
	{
		std::cout << name << " has no weapon to attack with" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
