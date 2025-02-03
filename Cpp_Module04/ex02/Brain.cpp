#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.getIdea(i);
	return *this;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return ideas[i];
	return NULL;
}

void Brain::setIdea(std::string idea, int i)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
		
}
