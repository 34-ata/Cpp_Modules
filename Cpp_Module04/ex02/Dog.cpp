#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea("I am a dog", i);
	type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const std::string idea)
{
	brain = new Brain();
	for (int i = 0; i < 100; i++)
			brain->setIdea(idea, i);
	type = "Dog";
	std::cout << "Special constructor called for Dog" << std::endl;
}
Dog::~Dog(void)
{
	delete brain;
	std::cout << "Destructor called for Dog" << std::endl;
}

Dog::Dog(const Dog& other)
{
	type = other.type;
	brain = new Brain();
	*brain = *other.brain;
}

Dog& Dog::operator=(const Dog& other)
{
	type = other.type;
	*brain = *other.brain;
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

void Dog::printIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << brain->getIdea(i) << std::endl;
}
