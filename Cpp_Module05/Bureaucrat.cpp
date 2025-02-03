#include "Bureaucrat.hpp"
#include <limits>

Bureaucrat::Bureaucrat() : grade(150), name("Default Bureaucrat") {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade > std::numeric_limits<int>::max())
        throw GradeTooHighException();
    if (grade < std::numeric_limits<int>::min())
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->name = name;
        this->grade = other.grade;
    }
    return *this;
}
