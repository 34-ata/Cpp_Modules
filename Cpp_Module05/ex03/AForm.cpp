#include "AForm.hpp"

AForm::AForm() : grade_to_execute(150), grade_to_sign(150), name("Default"), is_it_signed(false) {}

AForm::AForm(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute) : grade_to_execute(grade_to_execute), grade_to_sign(grade_to_sign), name(name), is_it_signed(false)
{
    if (grade_to_sign > 150 || grade_to_sign < 1)
    {
        std::cout << name << "'s grade_to_sign value range must be in 1-150. Parameter is " << grade_to_sign << "." << std::endl; 
        throw GradeTooLowException();
    }
    if (grade_to_execute > 150 || grade_to_execute < 1)
    {
        std::cout << name << "'s grade_to_execute value range must be in 1-150. Parameter is " << grade_to_execute << "." << std::endl; 
        throw GradeTooHighException();
    }   
}

AForm::~AForm(){}

std::string AForm::getName() const
{
    return name;
}

unsigned int AForm::getGradeToExecute() const
{
    return grade_to_execute;
}

unsigned int AForm::getGradeToSign() const
{
    return grade_to_sign;
}

bool AForm::getIsItSigned() const
{
    return is_it_signed;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign) {
        std::cout << bureaucrat.getName() << " could not sign " << name << ": Bureaucrat's grade (" 
                  << bureaucrat.getGrade() << ") is lower than the required grade (" 
                  << grade_to_sign << ")." << std::endl;
        throw GradeTooLowException();
    }
    is_it_signed = true;
    std::cout << bureaucrat.getName() << " signed " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& Form)
{
    os << "Form Name: " << Form.getName() << "\n"
       << "Grade required to sign: " << Form.getGradeToSign() << "\n"
       << "Grade required to execute: " << Form.getGradeToExecute() << "\n"
       << "Signed: " << (Form.getIsItSigned() ? "True" : "False") << std::endl;
    return os;
}