#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;
}

Cat::Cat(const Cat& other)
{
	type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::getType(void) const
{
	return this->type;
}

