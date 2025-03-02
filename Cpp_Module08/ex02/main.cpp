#include "MutantStack.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

void testFromPdf()
{
    std::cout << GREEN "Testing MutantStack with test from the PDF" RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << GREEN "Top element: " RED << mstack.top() << RESET << std::endl;
    mstack.pop();
    std::cout << GREEN "Size of mstack: " RED <<  mstack.size() << RESET << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << GREEN "Elements of mstack: " RESET << std::endl;
    while (it != ite)
    {
        std::cout << RED << *it << RESET << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

}

void testIterator()
{
    std::cout <<  GREEN "Starting the test of mine for iterator feature." RESET << std::endl;
    MutantStack<int> stack;

    stack.push(10);
    std::cout << GREEN "Adding 10 to stack." RESET << std::endl;
    stack.push(20);
    std::cout << GREEN "Adding 20 to stack." RESET << std::endl;
    stack.push(30);
    std::cout << GREEN "Adding 30 to stack." RESET << std::endl;

    MutantStack<int>::iterator it = stack.begin();
    
    std::cout << GREEN "First element of stack: " RED << *it << RESET << std::endl;
    if (*it != 10)
       { std::cerr << RED "Test failed: Iterator should point to 10" RESET << std::endl; return; }
    
    ++it;
    std::cout << GREEN "Secont element of stack: " RED << *it << RESET << std::endl;
    if (*it != 20)
        { std::cerr << RED "Test failed: Iterator should point to 20" RESET << std::endl; return; }
    
    ++it;
    std::cout << GREEN "Third element of stack: " RED << *it << RESET << std::endl;
    if (*it != 30)
        { std::cerr << RED "Test failed: Iterator should point to 30" RESET << std::endl; return; }

    ++it;
    if (it != stack.end())
        { std::cerr << RED "Test failed: Iterator should be at the end after moving past the last element" RESET << std::endl; return; }

    std::cout << GREEN "Iterator test passed!" RESET << std::endl;
}

int main()
{
    testFromPdf();
    testIterator();
    return 0;
}
