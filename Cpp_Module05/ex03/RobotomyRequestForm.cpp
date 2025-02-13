#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("Robotomy Request Form", 72, 45), target(target) {  }

RobotomyRequestForm::~RobotomyRequestForm() {  }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {(void)other;}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {(void)other;return *this;}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getIsItSigned())
		throw Form::GradeTooLowException();

	if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();

	std::cout << "****DADADADA****" << std::endl;
    if (rand() % 2 == 0)
        std::cout << target + " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}
