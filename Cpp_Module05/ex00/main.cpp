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
	try
	{
		Bureaucrat bro4("Bro4", 150);
		std::cout << bro4;
		bro4.decrementGrade(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat bro5("Bro5", 1);
		std::cout << bro5;
		bro5.incrementGrade(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	
	
	return (0);
}