#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea("I am a cat", i);
	type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const std::string idea)
{
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(idea, i);
	type = "Cat";
	std::cout << "Special constructor called for Cat" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Destructor called for Cat" << std::endl;
}

Cat::Cat(const Cat& other)
{
	type = other.type;
	brain = new Brain();
	*brain = *other.brain;
}

Cat& Cat::operator=(const Cat& other)
{
	type = other.type;
	*brain = *other.brain;
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

void Cat::printIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << brain->getIdea(i) << std::endl;
}
