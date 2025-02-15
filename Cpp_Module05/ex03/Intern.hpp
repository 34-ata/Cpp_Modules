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
		AForm *makeForm(const std::string &FormName, const std::string &FormTarget);
};
