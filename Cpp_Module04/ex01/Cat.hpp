#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat(const std::string idea);
		Cat& operator=(const Cat& other);
		void makeSound() const;
		std::string getType() const;
		void printIdeas() const;
	private:
		Brain* brain;
};

#endif
