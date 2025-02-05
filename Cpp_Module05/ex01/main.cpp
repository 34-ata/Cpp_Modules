#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bureaucrat1("John", 3);
    Bureaucrat bureaucrat2("Alice", 1);
    Bureaucrat bureaucrat3("Bob", 5);

    Form form1("FormA", 2, 5);
    Form form2("FormB", 1, 5);

    std::cout << BLUE << "\n--- Testing Form 1 (FormA) ---" << RESET << std::endl;
    std::cout << form1 << std::endl;
    std::cout << BLUE << "\nTrying to sign FormA with John (Grade 3):" << RESET << std::endl;
    try
    {
        bureaucrat1.signForm(form1);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\nTrying to sign FormA with Alice (Grade 1):" << RESET << std::endl;
    try
    {
        bureaucrat2.signForm(form1);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\nTrying to sign FormA with Bob (Grade 5):" << RESET << std::endl;
    try
    {
        bureaucrat3.signForm(form1);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n--- Testing Form 2 (FormB) ---" << RESET << std::endl;
    std::cout << form2 << std::endl;
    std::cout << BLUE << "\nTrying to sign FormB with John (Grade 3):" << RESET << std::endl;
    try
    {
        bureaucrat1.signForm(form2);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\nTrying to sign FormB with Alice (Grade 1):" << RESET << std::endl;
    try
    {
        bureaucrat2.signForm(form2);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\nTrying to sign FormB with Bob (Grade 5):" << RESET << std::endl;
    try
    {
        bureaucrat3.signForm(form2);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}