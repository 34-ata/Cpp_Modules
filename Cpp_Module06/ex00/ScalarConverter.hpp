#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

#define FLOAT 0
#define DOUBLE 1

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		static void convert(const std::string &str);
};

int	checkChar(const std::string &str);
int	checkInt(const std::string &str);
int	checkFloatDouble(const std::string &str, bool);


#endif