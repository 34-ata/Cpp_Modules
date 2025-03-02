#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error: The program requires at least two numbers." << std::endl, 1);
    PmergeMe exec;
    exec.executer(ac, av);
}