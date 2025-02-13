#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) {(void)other;}
Intern &Intern::operator=(const Intern &other) {(void)other;return *this;}

Form* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

Form* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

Form* createPresidentialPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	const std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (*formCreators[3])(const std::string &) = {&createShrubbery, &createRobotomy, &createPresidentialPardon};
	
	for (int i = 0; i < 3; i++)
		if (formName == formTypes[i])
			return formCreators[i](formTarget);

	throw std::invalid_argument("Unknown form type: " + formName);
}
