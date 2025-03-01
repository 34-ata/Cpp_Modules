#include <iostream>
#include "Span.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

void testAddNumber()
{
    Span sp(5);
    try
    {
        std::cout << "Adding numbers individually:" << std::endl;

        sp.addNumber(10);
        std::cout << GREEN << "Added 10" << RESET << std::endl;
        sp.addNumber(20);
        std::cout << GREEN << "Added 20" << RESET << std::endl;
        sp.addNumber(30);
        std::cout << GREEN << "Added 30" << RESET << std::endl;
        sp.addNumber(40);
        std::cout << GREEN << "Added 40" << RESET << std::endl;
        sp.addNumber(50);
        std::cout << GREEN << "Added 50" << RESET << std::endl;

        std::cout << GREEN << "Trying to add another number." << RESET << std::endl;
        sp.addNumber(60);
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << RED << "Test Failed: " << e.what() << RESET << std::endl;
    }
}

void testAddNumbers()
{
    Span sp(20000);
    try
    {
        std::cout << GREEN "Adding 20000 numbers:" << std::endl;

        sp.addNumbers(20000);
        std::cout << GREEN << "Successfully added 20000 numbers" << RESET << std::endl;

        std::cout << GREEN << "Trying to add 20001" << RESET << std::endl;
        sp.addNumber(20001);
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << RED << "Test Failed: " << e.what() << RESET << std::endl;
    }
}

void testShortestSpan()
{
    Span sp(5);
    try
    {
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
        sp.addNumber(50);

        int result = sp.shortestSpan();
        std::cout << GREEN << "Test Passed: Shortest Span is " << result << RESET << std::endl;
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << RED << "Test Failed: " << e.what() << RESET << std::endl;
    }
}

void testLongestSpan()
{
    Span sp(5);
    try
    {
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
        sp.addNumber(50);

        int result = sp.longestSpan();
        std::cout << GREEN << "Test Passed: Longest Span is " << result << RESET << std::endl;
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << RED << "Test Failed: " << e.what() << RESET << std::endl;
    }
}

int main()
{
    std::cout << GREEN "Testing Span Class" RESET << std::endl;

    testAddNumber();
    testAddNumbers();
    testShortestSpan();
    testLongestSpan();

    return 0;
}
