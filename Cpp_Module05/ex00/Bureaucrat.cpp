#include "Bureaucrat.hpp"
#include <limits>
#include <string> 

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150) {}
Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : name(name)
{
    if (grade > 150)
    {
        std::cout << name << " [" << grade << "]'s "; 
        throw GradeTooLowException();
    }
    if (grade < 1)
    {
        std::cout << name << " [" << grade << "]'s ";
        throw GradeTooHighException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    (void)other;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name;
}

unsigned int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade(unsigned int increment)
{
    if (grade - increment < 1)
    {
        std::cout << this->name << " [" << grade - increment << "]'s ";
        throw GradeTooHighException();
    }
    grade -= increment;
}

void Bureaucrat::decrementGrade(unsigned int decrement)
{
    if (grade + decrement > 150)
    {
        std::cout << this->name << " [" << grade + decrement << "]'s ";
        throw GradeTooLowException();
    }
    grade += decrement;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << " [" << bureaucrat.getGrade() << "]" << std::endl;
    return (os);
}

