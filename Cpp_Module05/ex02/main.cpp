#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
    try
	{
		Bureaucrat bureaucrat("Darly", 40);

		ShrubberyCreationForm	shrubberyForm("home");

		bureaucrat.signForm(shrubberyForm);

		bureaucrat.executeForm(shrubberyForm);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}

	return (0);
}