#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cerr << "Error: The program requires exactly one argument." << std::endl;
    BitcoinExchange exchange;

    exchange.readFromDB();
    exchange.readFromFile(av[1]);
}