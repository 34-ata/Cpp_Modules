#include "PmergeMe.hpp"
#include <cstdlib>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    if (this != &cpy) {
        this->lst = cpy.lst;
        this->vec = cpy.vec;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    (void)copy;
    return *this;
}

template <typename T>
void printContainer(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


int checkIfNumber(const std::string& value)
{
    for (int i = 0; i < (int)value.length(); i++)
    {
        if (!(value[i] >= '0' && value[i] <= '9'))
        {
            std::cerr << "Error: Non-numeric character found: " << value << std::endl;
            return 1;
        }
    }
    return 0;
}

int PmergeMe::validateAndFill(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (checkIfNumber(argv[i]))
            return 1;
        int value = std::atoi(argv[i]);
        if (value < 1)
        {
            std::cerr << "Error: Value must be greater than 0: " << argv[i] << std::endl;
            return 1;
        }
        vec.push_back(value);
        lst.push_back(value);
    }
    return 0;
}

void PmergeMe::executer(int ac, char **av)
{
    if (validateAndFill(ac, av))
        return ;
    printContainer(vec);
}
