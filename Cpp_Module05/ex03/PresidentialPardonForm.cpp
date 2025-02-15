#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5), target(target) {  }

PresidentialPardonForm::~PresidentialPardonForm() {  }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) {(void)other;}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {(void)other;return *this;}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getIsItSigned())
		throw AForm::GradeTooLowException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
