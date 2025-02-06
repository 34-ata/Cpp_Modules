#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target) {  }

ShrubberyCreationForm::~ShrubberyCreationForm() {  }

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsItSigned())
		throw AForm::GradeTooLowException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::string str = target + "_shrubbery";
	std::ofstream outputFile(str.c_str());

	if (outputFile)
	{
		outputFile << "                      ___" << std::endl;
		outputFile << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
		outputFile << "             ,-'          __,,-- \\" << std::endl;
		outputFile << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
		outputFile << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
		outputFile << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
		outputFile << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
		outputFile << "     (     ,-'                  `." << std::endl;
		outputFile << "      `._,'     _   _             ;" << std::endl;
		outputFile << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
		outputFile << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
		outputFile << "        `--\'   \"Hb  HH  dF\"" << std::endl;
		outputFile << "                \"Hb HH dF" << std::endl;
		outputFile << "                 \"HbHHdF" << std::endl;
		outputFile << "                  |HHHF" << std::endl;
		outputFile << "                  |HHH|" << std::endl;
		outputFile << "                  |HHH|" << std::endl;
		outputFile << "                  |HHH|" << std::endl;
		outputFile << "                  |HHH|" << std::endl;
		outputFile << "                  dHHHb" << std::endl;
		outputFile << "                .dFd|bHb.               o" << std::endl;
		outputFile << "      o       .dHFdH|HbTHb.          o /" << std::endl;
		outputFile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
		outputFile << "##########################################" << std::endl;
	}
	else
	{
		throw std::runtime_error("Failed to create shrubbery file for " + target + ".");
	}
	outputFile.close();
}