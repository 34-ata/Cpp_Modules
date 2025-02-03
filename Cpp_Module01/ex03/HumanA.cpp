#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& new_weapon) : weapon(new_weapon), name(name){}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
