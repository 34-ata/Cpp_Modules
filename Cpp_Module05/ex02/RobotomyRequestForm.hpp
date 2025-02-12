#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();

	void	execute(const Bureaucrat& executor) const;
};

#endif