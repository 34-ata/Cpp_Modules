#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return this->type;
}

