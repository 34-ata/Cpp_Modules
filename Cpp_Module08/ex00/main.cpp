#include "easyfind.hpp"
#include <vector>
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

void testVector()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    std::cout << GREEN "Vector contents: " RESET;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << RED << *it << RESET<< " ";
    std::cout << std::endl;

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << GREEN << "Found: " << RED << *it << " " << GREEN << "in vector." << RESET << std::endl;
    }
    catch (const ValueNotFoundException &e)
    {
        std::cout << RED << "Exception caught in vector: " << GREEN << e.what() << " " << RED << "(Value: 5)" << RESET << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << GREEN << "Found: " << RED << *it << " in vector." RESET << std::endl;
    }
    catch (const ValueNotFoundException &e)
    {
        std::cout << RED << "Exception caught in vector: " << GREEN << e.what() << " " << RED << "(Value: 20)" << RESET << std::endl;
    }
}

void testList()
{
    std::list<int> lst;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i);

    std::cout << GREEN "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << RED << *it << RESET << " ";
    std::cout << std::endl;

    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << GREEN << "Found: " << RED << *it << GREEN " in list." << std::endl;
    }
    catch (const ValueNotFoundException &e)
    {
        std::cout << RED << "Exception caught in list: " << GREEN << e.what() << " " << RED << "(Value: 15)" << RESET << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << GREEN << "Found: " << RED << *it << GREEN " in list." RESET << std::endl;
    }
    catch (const ValueNotFoundException &e)
    {
        std::cout << RED << "Exception caught in list: " << GREEN << e.what() << " " << RED << "(Value: 20)" << RESET << std::endl;
    }
}

int main()
{
    std::cout << GREEN "Testing with vector:" RESET << std::endl;
    testVector();
    
    std::cout << GREEN "\nTesting with list:" RESET << std::endl;
    testList();
    
    return 0;
}
