#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    if (this != &cpy)
        this->dataBase = cpy.dataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    (void)copy;
    return *this;
}


void    BitcoinExchange::readFromDB()
{
    std::ifstream file("data.csv");
    
    if (!file.is_open())
    {
        std::cerr << "Cannot open given file." << std::endl; return ;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;
        float rate;

        std::getline(ss, date, ',');
        std::getline(ss, rateStr, ',');
        rate = std::atof(rateStr.c_str());

       dataBase.insert(std::pair<std::string, float>(date, rate));
    }
}

std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

void BitcoinExchange::findDateAndPrint(const std::string& date, float value)
{
    std::map<std::string, float>::iterator it = dataBase.find(date);
    
    if (it != dataBase.end())
    {
        std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
    }
    else
    {
        it = dataBase.lower_bound(date);
        if (it != dataBase.begin()) {
            --it;
            std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
        }
        else
        {
            std::cout << "Error: no valid date found for: " << date << std::endl;
        }
    }
}

void BitcoinExchange::checkLineAndPrint(const std::string& line)
{
    size_t delimiterPos = line.find('|');
    if (delimiterPos != std::string::npos)
    {
        std::string date = trim(line.substr(0, delimiterPos));
        std::string valueStr = trim(line.substr(delimiterPos + 1));

        float value = std::atof(valueStr.c_str());

        int year = std::atoi(date.substr(0, 4).c_str());
        int month = std::atoi(date.substr(5, 2).c_str());
        int day = std::atoi(date.substr(8, 2).c_str());

        if (year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            std::cout << "Error: bad input => " << date << std::endl;
        }
        else if (value < 0)
        {
            std::cout << "Error: not a positive number. = " << value << std::endl;
        }
        else if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
        }
        else
        {
            findDateAndPrint(date, value);
        }
    }
    else
    {
        std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
    }
}

void BitcoinExchange::readFromFile(const std::string& fileName)
{
    std::ifstream file(fileName.c_str());

    if (!file.is_open())
    {
        std::cerr << "Cannot open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
        checkLineAndPrint(line);
    file.close();
}

