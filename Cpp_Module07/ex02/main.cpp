#include <iostream>
#include "Array.tpp"

#define RESET   "\033[0m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define RED     "\033[1;31m"
#define MAGENTA "\033[1;35m"

int main()
{
    try {
        Array<int> intArray(5);
        std::cout << BLUE "Array size: " << intArray.size() << RESET << std::endl;
        
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10;
        
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << GREEN "Element at index " << i << ": " << intArray[i] << RESET << std::endl;

        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "C++";
        
        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << CYAN "String at index " << i << ": " << strArray[i] << RESET << std::endl;
        
        Array<int> copiedArray = intArray;
        std::cout << MAGENTA "Copied Array element at index 2: " << copiedArray[2] << RESET << std::endl;

        Array<int> assignedArray(3);
        assignedArray = intArray;
        std::cout << GREEN "Assigned Array element at index 4: " << assignedArray[4] << RESET << std::endl;

        std::cout << RED "Attempting to access an invalid index..." RESET << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const Array<int>::InvalidIndexException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
