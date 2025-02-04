#include <iostream>

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bro1("Bro1", 15);
		std::cout << bro1;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat bro2("Bro2", 0);
		std::cout << bro2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat bro3("Bro3", 199);
		std::cout << bro3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}