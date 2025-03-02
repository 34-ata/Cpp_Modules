#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: The program requires exactly one argument." << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.executer(av[1]);
}