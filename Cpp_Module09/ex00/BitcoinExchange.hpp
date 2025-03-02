#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> dataBase;
    public:
        BitcoinExchange();
        ~BitcoinExchange(); 
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange& operator=(const BitcoinExchange &cpy);

    public:
        void readFromDB();
        void readFromFile(const std::string&);
        void findDateAndPrint(const std::string& date, float value);
        void checkLineAndPrint(const std::string& line);
};

#endif