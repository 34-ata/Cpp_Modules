#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main()
{
    try
	{
		Bureaucrat bureaucrat("Daryl", 1);

		ShrubberyCreationForm	shrubberyForm("Home");
		PresidentialPardonForm presidentialPardonForm("Office");
		RobotomyRequestForm robotomyRequestForm("Machine");

		bureaucrat.signForm(shrubberyForm);
		bureaucrat.executeForm(shrubberyForm);

		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);

		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
	
	std::cout << RED << "ANOTHER TEST STARTING" << RESET << std::endl;

	try
	{
		Bureaucrat bureaucrat("Shelby", 7);

		ShrubberyCreationForm shrubberyForm("Home");
		PresidentialPardonForm presidentialPardonForm("Office");
		RobotomyRequestForm robotomyRequestForm("Machine");

		bureaucrat.signForm(shrubberyForm);
		bureaucrat.executeForm(shrubberyForm);

		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);

		bureaucrat.signForm(presidentialPardonForm);
		std::cout << RED << "NOW, THIS STEP MUST CAUSE AN ERROR." << RESET << std::endl;
		bureaucrat.executeForm(presidentialPardonForm);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occured: " << e.what() << std::endl;
	}
	return (0);
}
