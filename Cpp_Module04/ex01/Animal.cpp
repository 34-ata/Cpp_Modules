#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal& other)
{
	type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "Unrecognized animal sound" << std::endl;
}

