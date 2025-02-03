#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete i;
		delete j;
	}
	{
		Dog* j = new Dog("I think I am a dog");
		Dog* i = new Dog();

		j->printIdeas();
		i->printIdeas();
		*j = *i;
		std::cout << "--------------------------------------" << std::endl;
		j->printIdeas();
		i->printIdeas();
		delete i;
		delete j;
	}
	{
		const Animal* animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}

	return 0;
}
