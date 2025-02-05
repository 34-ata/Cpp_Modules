#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string& name, unsigned int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
    public:
        std::string getName() const;
        unsigned int getGrade() const;
        void incrementGrade(unsigned int increment);
        void decrementGrade(unsigned int decrement);
    private:
        const std::string name;
        unsigned int grade;
    private:
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "grade too high!\n";
                }

        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "grade too low!\n";
                }

        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif