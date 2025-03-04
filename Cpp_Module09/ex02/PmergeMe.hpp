#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
    private:
        std::list<int> lst;
        std::vector<int> vec;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);
    public:
        int validateAndFill(int, char**);
        void executer(int, char**);
        std::vector<int> sortVec(std::vector<int>&);
        std::list<int> sortLst(std::list<int>&);
};


#endif