#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		std::string getIdea(int i) const;
		void setIdea(std::string idea, int i);
	private:
		std::string ideas[100];
};

#endif
