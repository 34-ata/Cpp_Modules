#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called for Dog" << std::endl;
}

Dog::Dog(const Dog& other)
{
	type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

std::string Dog::getType(void) const
{
	return this->type;
}

