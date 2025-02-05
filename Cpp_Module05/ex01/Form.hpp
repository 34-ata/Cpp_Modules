#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

class Bureaucrat;

class Form
{

    public:
        Form();
        Form(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
    public:
        std::string getName() const;
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExecute() const;
        bool getIsItSigned() const;
        void beSigned(Bureaucrat& Bureaucrat); 
    private:
        const unsigned int grade_to_execute;
        const unsigned int grade_to_sign;
        const std::string name;
        bool  is_it_signed;
    private:
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "grade too low!\n";
                }
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "grade too high!\n";
                }
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif