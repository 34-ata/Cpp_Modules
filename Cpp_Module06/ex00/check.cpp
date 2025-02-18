#include "ScalarConverter.hpp"

int checkSign(const std::string& str, size_t& start)
{
    if (str.empty()) return 0;
    if (str[0] == '-' || str[0] == '+')
    {
        start = 1;
        return (str.length() > 1);
    }
    return 1;
}

int checkChar(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}


int checkInt(const std::string& str)
{
    if (str.empty()) return 0;
    size_t start = 0;
    if (!checkSign(str, start)) return 0;

    for (size_t i = start; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}

int checkFloatDouble(const std::string& str, bool whichone)
{
    if (whichone == FLOAT && (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf"))
        return 1;
    if (whichone == DOUBLE && (str == "-inf" || str == "+inf" || str == "inf" || str == "nan"))
        return 1;
    if (str.empty()) return 0;

    size_t start = 0;
    bool hasDecimal = false, hasExponent = false, hasDigits = false;

    if (!checkSign(str, start)) return 0;

    for (size_t i = start; i < str.length(); ++i)
    {
        char c = str[i];
        if (std::isdigit(c))
            hasDigits = true;
        else if (c == '.')
        {
            if (hasDecimal || hasExponent) return 0;
            hasDecimal = true;
        }
        else if (c == 'e' || c == 'E')
        {
            if (hasExponent || !hasDigits) return 0;
            hasExponent = true;
            hasDigits = false;
        }
        else if (c == 'f' || c == 'F')
        {
            if (i != str.length() - 1) return 0;
        }
        else if (c == '-' || c == '+')
        {
            if (i == start || (str[i - 1] != 'e' && str[i - 1] != 'E'))
                return 0;
        }
        else
            return 0;
    }
    return hasDigits;
}
