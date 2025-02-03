#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
    private:
        const std::string name;
        unsigned char grade;
        class GradeTooHighException : std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade too high!\n";
                }

        };
        class GradeTooLowException : std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade too low!\n";
                }

        };
};