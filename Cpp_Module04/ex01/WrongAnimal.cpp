#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Unrecognized WrongAnimal sound" << std::endl;
}

