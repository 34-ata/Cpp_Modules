#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
	private:
		std::string str;
		int number;
		float decimal;
		double precision;
		bool isActive;
		char letter;

	public:
		Data();
		Data(const std::string &strValue, int intValue, float floatValue, double doubleValue, bool boolValue, char charValue);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();
	
	public:
		std::string getStr() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
		bool getBool() const;
		char getChar() const;

		void printData() const;
};

#endif
