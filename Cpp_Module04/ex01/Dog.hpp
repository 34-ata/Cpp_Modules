#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog(const std::string idea);
		Dog& operator=(const Dog& other);
		void makeSound() const;
		std::string getType(void) const;
		void printIdeas() const;
	private:
		Brain* brain;
};

#endif
