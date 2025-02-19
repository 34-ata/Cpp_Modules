#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){ (void)src; return *this; }

void convertChar(int &_int, float &_float, double &_double, char &_char, const std::string &_str)
{
    _char = _str[0];
    _int = static_cast<int>(_char);
    _float = static_cast<float>(_char);
    _double = static_cast<double>(_char);
}

void convertInt(int &_int, float &_float, double &_double, char &_char, const std::string &_str)
{
    int result = 0;
    bool isNegative = false;
    size_t start = 0;

    if (_str[0] == '-')
    {
        isNegative = true;
        start = 1;
    }
    else if (_str[0] == '+')
        start = 1;
    for (size_t i = start; i < _str.length(); ++i)
        result = result * 10 + (_str[i] - '0');
    if (isNegative)
        result = -result;

    _char = static_cast<char>(result);
    _float = static_cast<float>(result);
    _double = static_cast<double>(result);
    _int = result;
}

bool convertFloat(int &_int, float &_float, double &_double, char &_char, const std::string &_str)
{
    float result = 0.0f;
    float divisor = 1.0f;
    bool isNegative = false;
    bool isExponentNegative = false;
    bool inFraction = false;
    bool inExponent = false;
    float exponent = 0.0f;
    bool impossible = false;
    size_t i = 0;

    if (_str == "-inff")
    {
        impossible = true;
        _float = -std::numeric_limits<float>::infinity();
        _double = -std::numeric_limits<double>::infinity();
        return impossible;
    }
    else if (_str == "+inff" || _str == "inff")
    {
        impossible = true;
        _float = std::numeric_limits<float>::infinity();
        _double = std::numeric_limits<double>::infinity();
        return impossible;
    }
    else if (_str == "nanf")
    {
        impossible = true;
        _float = std::numeric_limits<float>::quiet_NaN();
        _double = std::numeric_limits<double>::quiet_NaN();
        return impossible;
    }

    if (_str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }
    else if (_str[0] == '+')
        i = 1;

    for (; i < _str.length(); ++i)
    {
        if (std::isdigit(_str[i]))
        {
            if (inExponent)
                exponent = exponent * 10.0f + (_str[i] - '0');
            else if (inFraction)
            {
                divisor *= 10.0f;
                result += (_str[i] - '0') / divisor;
            }
            else
                result = result * 10.0f + (_str[i] - '0');
        }
        else if (_str[i] == '.')
            inFraction = true;
        else if (_str[i] == 'e' || _str[i] == 'E')
            inExponent = true;
        else if (_str[i] == '-')
            isExponentNegative = true;
        else if (_str[i] == '+')
            isExponentNegative = false;
    }
    if (isExponentNegative)
        exponent = -exponent;

    result *= std::pow(10, exponent);

    if (isNegative)
        result = -result;

    _char = static_cast<char>(result);
    _int = static_cast<int>(result);
    _float = result;
    _double = static_cast<double>(result);

    return impossible;
}

bool convertDouble(int &_int, float &_float, double &_double, char &_char, const std::string &_str)
{
    double result = 0.0;
    double divisor = 1.0;
    bool isNegative = false;
    bool isExponentNegative = false;
    bool inFraction = false;
    bool inExponent = false;
    double exponent = 0.0;
    bool impossible = false;
    size_t i = 0;

    if (_str == "-inf")
    {
        impossible = true;
        _float = -std::numeric_limits<float>::infinity();
        _double = -std::numeric_limits<double>::infinity();
        return impossible;
    }
    else if (_str == "+inf" || _str == "inf")
    {
        impossible = true;
        _float = std::numeric_limits<float>::infinity();
        _double = std::numeric_limits<double>::infinity();
        return impossible;
    }
    else if (_str == "nan")
    {
        impossible = true;
        _float = std::numeric_limits<float>::quiet_NaN();
        _double = std::numeric_limits<double>::quiet_NaN();
        return impossible;
    }

    if (_str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }
    else if (_str[0] == '+')
        i = 1;

    for (; i < _str.length(); ++i)
    {
        if (std::isdigit(_str[i]))
        {
            if (inExponent)
                exponent = exponent * 10.0 + (_str[i] - '0');
            else if (inFraction)
            {
                divisor *= 10.0;
                result += (_str[i] - '0') / divisor;
            }
            else
                result = result * 10.0 + (_str[i] - '0');
        }
        else if (_str[i] == '.')
            inFraction = true;
        else if (_str[i] == 'e' || _str[i] == 'E')
            inExponent = true;
        else if (_str[i] == '-')
            isExponentNegative = true;
        else if (_str[i] == '+')
            isExponentNegative = false;
    }

    if (isExponentNegative)
        exponent = -exponent;

    result *= std::pow(10, exponent);

    if (isNegative)
        result = -result;

    _char = static_cast<char>(result);
    _int = static_cast<int>(result);
    _float = static_cast<float>(result);
    _double = result;

    return impossible;
}

void print(int _int, float _float, double _double, char _char, bool impossible)
{
    std::cout << "char: ";
    if (!impossible && std::isprint(_char))
        std::cout << "'" << _char << "'" << std::endl;
    else if (impossible)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    if (impossible)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _int << std::endl;
    
    std::cout << "float: " << _float;
    if (_float == static_cast<int>(_float))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << _double;
    if (_double == static_cast<int>(_double))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    int _int = 0;
    float _float = 0.0f;
    double _double = 0.0;
    char _char = 0;
    bool impossible = false;

    if (checkChar(str))
        convertChar(_int, _float, _double, _char, str);
    else if (checkInt(str))
        convertInt(_int, _float, _double, _char, str);
    else if (checkFloatDouble(str, FLOAT))
        impossible = convertFloat(_int, _float, _double, _char, str);
    else if (checkFloatDouble(str, DOUBLE))
        impossible = convertDouble(_int, _float, _double, _char, str);
    else
    {
        std::cout << "Error: Invalid input" << std::endl;
        return;
    }
    print(_int, _float, _double, _char, impossible);
}
