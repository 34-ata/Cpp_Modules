#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

class Bureaucrat;

class AForm
{

    public:
        AForm();
        AForm(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute);
        virtual ~AForm();
    public:
        std::string getName() const;
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExecute() const;
        bool getIsItSigned() const;
        void beSigned(Bureaucrat& Bureaucrat); 
        virtual void execute(const Bureaucrat &executor) const = 0;
    private:
        const unsigned int grade_to_execute;
        const unsigned int grade_to_sign;
        const std::string name;
        bool  is_it_signed;
    public:
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

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
