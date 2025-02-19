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
    Data *data2 = Serializer::deserialize(raw1);

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

    Data *data3 = new Data("NegativeTest", -999, -999.99f, -123.456, false, 'Z');
    uintptr_t raw2 = Serializer::serialize(data3);
    Data *data4 = Serializer::deserialize(raw2);

    std::string expectedOutput2 =
        "Data 3:\nStr: NegativeTest\nInt: -999\nFloat: -999.99\nDouble: -123.456\nBoolean: False\nChar: Z\n"
        "Data 4:\nStr: NegativeTest\nInt: -999\nFloat: -999.99\nDouble: -123.456\nBoolean: False\nChar: Z\n";
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
    displayResult("Edge Case with Negative and Zero Values", expectedOutput2 == actualOutput2.str(), expectedOutput2, actualOutput2.str());
    delete data3;

    Data *data5 = new Data("LargeTest", 1000000000, 1.23e30f, 1.23e100, true, '*');
    uintptr_t raw3 = Serializer::serialize(data5);
    Data *data6 = Serializer::deserialize(raw3);

    std::string expectedOutput3 =
        "Data 5:\nStr: LargeTest\nInt: 1000000000\nFloat: 1.23e+30\nDouble: 1.23e+100\nBoolean: True\nChar: *\n"
        "Data 6:\nStr: LargeTest\nInt: 1000000000\nFloat: 1.23e+30\nDouble: 1.23e+100\nBoolean: True\nChar: *\n";
    std::ostringstream actualOutput3;
    actualOutput3 << "Data 5:" << std::endl
                  << "Str: " << data5->getStr() << std::endl
                  << "Int: " << data5->getInt() << std::endl
                  << "Float: " << data5->getFloat() << std::endl
                  << "Double: " << data5->getDouble() << std::endl
                  << "Boolean: " << (data5->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data5->getChar() << std::endl
                  << "Data 6:" << std::endl
                  << "Str: " << data6->getStr() << std::endl
                  << "Int: " << data6->getInt() << std::endl
                  << "Float: " << data6->getFloat() << std::endl
                  << "Double: " << data6->getDouble() << std::endl
                  << "Boolean: " << (data6->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data6->getChar() << std::endl;
    displayResult("Test with Large Values", expectedOutput3 == actualOutput3.str(), expectedOutput3, actualOutput3.str());
    delete data5;

    Data *data7 = new Data("SpecialChars!@#$", 123, 456.78f, 9.8765, true, '*');
    uintptr_t raw4 = Serializer::serialize(data7);
    Data *data8 = Serializer::deserialize(raw4);

    std::string expectedOutput4 =
        "Data 7:\nStr: SpecialChars!@#$\nInt: 123\nFloat: 456.78\nDouble: 9.8765\nBoolean: True\nChar: *\n"
        "Data 8:\nStr: SpecialChars!@#$\nInt: 123\nFloat: 456.78\nDouble: 9.8765\nBoolean: True\nChar: *\n";
    std::ostringstream actualOutput4;
    actualOutput4 << "Data 7:" << std::endl
                  << "Str: " << data7->getStr() << std::endl
                  << "Int: " << data7->getInt() << std::endl
                  << "Float: " << data7->getFloat() << std::endl
                  << "Double: " << data7->getDouble() << std::endl
                  << "Boolean: " << (data7->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data7->getChar() << std::endl
                  << "Data 8:" << std::endl
                  << "Str: " << data8->getStr() << std::endl
                  << "Int: " << data8->getInt() << std::endl
                  << "Float: " << data8->getFloat() << std::endl
                  << "Double: " << data8->getDouble() << std::endl
                  << "Boolean: " << (data8->getBool() ? "True" : "False") << std::endl
                  << "Char: " << data8->getChar() << std::endl;
    displayResult("Test with Special Characters in String and Char", expectedOutput4 == actualOutput4.str(), expectedOutput4, actualOutput4.str());
    delete data7;

    return 0;
}
