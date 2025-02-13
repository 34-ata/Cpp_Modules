#include "AForm.hpp"
#include <string>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

	public:
		Form *makeForm(const std::string &formName, const std::string &formTarget);
};
