#include <iostream>
#include "iter.hpp"

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET "\033[0m"

template <typename T>
void printElement(T &element)
{
    std::cout << element << " ";
}

template <typename T>
void doubleElement(T &element)
{
    element *= 2;
}

void toLowerCase(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << BLUE "Original array: ";
    iter(arr, len, printElement<int>);
    std::cout << RESET << std::endl;

    iter(arr, len, doubleElement<int>);

    std::cout << GREEN "After doubling: ";
    iter(arr, len, printElement<int>);
    std::cout << RESET << std::endl;

    std::string strArr[] = {"Hello", "World", "C++", "Templates"};
    size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << CYAN "Original string array: ";
    iter(strArr, strLen, printElement<std::string>);
    std::cout << RESET << std::endl;

    iter(strArr, strLen, toLowerCase);

    std::cout << MAGENTA "After changing to lowercase: ";
    iter(strArr, strLen, printElement<std::string>);
    std::cout << RESET << std::endl;

    return 0;
}
