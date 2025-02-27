#include <iostream>
#include <sstream>
#include <iomanip>
#include "Serializer.hpp"

void displayResult(const std::string &testName, bool passed, const std::string &expected, const std::string &actual)
{
    std::cout << "Test: " << testName << std::endl;
    std::cout << "Expected Output:\n" << expected << std::endl;
    std::cout << "Actual Output:\n" << actual << std::endl;
    
    if (passed)
        std::cout << "\033[32mPASSED\033[0m" << std::endl;
    else
        std::cout << "\033[31mFAILED\033[0m" << std::endl;

    std::cout << "---------------------------------" << std::endl;
}

int main()
{
    Data *data1 = new Data("Hello", 42, 42.42f, 42.4242, true, 'A');
    uintptr_t raw1 = Serializer::serialize(data1);
    std::cout << "Serialized Data 1 to uintptr_t: " << raw1 << std::endl;
    Data *data2 = Serializer::deserialize(raw1);
    std::cout << "Deserialized Data 1 from uintptr_t: " << raw1 << std::endl;

    std::string expectedOutput1 =
        "Data 1:\nStr: Hello\nInt: 42\nFloat: 42.42\nDouble: 42.4242\nBoolean: True\nChar: A\n"
        "Data 2:\nStr: Hello\nInt: 42\nFloat: 42.42\nDouble: 42.4242\nBoolean: True\nChar: A\n";
    std::ostringstream actualOutput1;
    actualOutput1 << "Data 1:" << std::endl
                  << "Str: " << data1->getStr() << std::endl
                  << "Int: " << data1->getInt() << std::endl
                  << "Float: " << data1->getFloat() << std::endl
                  << "Double: " << data1->getDouble() << std::endl
                  << "Boolean: " << (data1->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data1->getChar() << std::endl
                  << "Data 2:" << std::endl
                  << "Str: " << data2->getStr() << std::endl
                  << "Int: " << data2->getInt() << std::endl
                  << "Float: " << data2->getFloat() << std::endl
                  << "Double: " << data2->getDouble() << std::endl
                  << "Boolean: " << (data2->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data2->getChar() << std::endl;
    displayResult("Standard Test Case", expectedOutput1 == actualOutput1.str(), expectedOutput1, actualOutput1.str());
    delete data1;

    Data *data3 = new Data("Test!@#", -999, 1.23e30f, -123.456, false, '*');
    uintptr_t raw2 = Serializer::serialize(data3);
    std::cout << "Serialized Data 3 to uintptr_t: " << raw2 << std::endl;
    Data *data4 = Serializer::deserialize(raw2);
    std::cout << "Deserialized Data 3 from uintptr_t: " << raw2 << std::endl;

    std::string expectedOutput2 =
        "Data 3:\nStr: Test!@#\nInt: -999\nFloat: 1.23e+30\nDouble: -123.456\nBoolean: False\nChar: *\n"
        "Data 4:\nStr: Test!@#\nInt: -999\nFloat: 1.23e+30\nDouble: -123.456\nBoolean: False\nChar: *\n";
    std::ostringstream actualOutput2;
    actualOutput2 << "Data 3:" << std::endl
                  << "Str: " << data3->getStr() << std::endl
                  << "Int: " << data3->getInt() << std::endl
                  << "Float: " << data3->getFloat() << std::endl
                  << "Double: " << data3->getDouble() << std::endl
                  << "Boolean: " << (data3->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data3->getChar() << std::endl
                  << "Data 4:" << std::endl
                  << "Str: " << data4->getStr() << std::endl
                  << "Int: " << data4->getInt() << std::endl
                  << "Float: " << data4->getFloat() << std::endl
                  << "Double: " << data4->getDouble() << std::endl
                  << "Boolean: " << (data4->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data4->getChar() << std::endl;
    displayResult("Edge Case Test (Negative, Large, Special Chars)", expectedOutput2 == actualOutput2.str(), expectedOutput2, actualOutput2.str());
    delete data3;

    return 0;
}