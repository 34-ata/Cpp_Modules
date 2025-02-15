#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Daryl", 1);
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception occured: " << e.what() << std::endl;
	}
	
	std::cout << RED << "Starting a test that will must be failed" << RESET << std::endl;

	try
	{
		Bureaucrat bureaucrat("Thomas", 1);
		Intern someRandomIntern;
		AForm* Form;

		Form = someRandomIntern.makeForm("presidential pardoning", "White");
		bureaucrat.signForm(*Form);
		bureaucrat.executeForm(*Form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception occured: " << e.what() << std::endl;
	}

	return (0);
}
