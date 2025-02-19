#include "Data.hpp"

Data::Data() : str("Default String"), number(0), decimal(0.0f), precision(0.0), isActive(false), letter('D') {}

Data::Data(const std::string &strValue, int intValue, float floatValue, double doubleValue, bool boolValue, char charValue)
    : str(strValue), number(intValue), decimal(floatValue), precision(doubleValue), isActive(boolValue), letter(charValue) {}

Data::Data(const Data &other)
    : str(other.str), number(other.number), decimal(other.decimal), precision(other.precision), isActive(other.isActive), letter(other.letter) {}

Data &Data::operator=(const Data &other) {
    if (this != &other) {
        str = other.str;
        number = other.number;
        decimal = other.decimal;
        precision = other.precision;
        isActive = other.isActive;
        letter = other.letter;
    }
    return *this;
}

Data::~Data() {}

std::string Data::getStr() const { return str; }

int Data::getInt() const { return number; }

float Data::getFloat() const { return decimal; }

double Data::getDouble() const { return precision; }

bool Data::getBool() const { return isActive; }

char Data::getChar() const { return letter; }

void Data::printData() const
{
    std::cout << "String: " << str << std::endl;
    std::cout << "Integer: " << number << std::endl;
    std::cout << "Float: " << decimal << std::endl;
    std::cout << "Double: " << precision << std::endl;
    std::cout << "Boolean: " << (isActive ? "True" : "False") << std::endl;
    std::cout << "Char: " << letter << std::endl;
}
