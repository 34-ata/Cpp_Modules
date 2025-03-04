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

std::list<int> mergeLst(std::list<int> &left, std::list<int> &right)
{
    std::list<int> res;
    std::list<int>::iterator it1 = left.begin();
    std::list<int>::iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end())
    {
        if (*it1 <= *it2)
            res.push_back(*it1++);
        else
            res.push_back(*it2++);
    }
    while (it1 != left.end())
        res.push_back(*it1++);
    while (it2 != right.end())
        res.push_back(*it2++);

    return res;
}

std::list<int> PmergeMe::sortLst(std::list<int> &lst)
{
    if (lst.size() <= 1) return lst;
    
    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);
    std::list<int> left(lst.begin(), mid);
    std::list<int> right(mid, lst.end());
    
    left = sortLst(left);
    right = sortLst(right);
    
    return mergeLst(left, right);
}

std::vector<int> mergeVec(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> res;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            res.push_back(left[i++]);
        else
            res.push_back(right[j++]);
    }
    while (i < left.size())
        res.push_back(left[i++]);
    while (j < right.size())
        res.push_back(right[j++]);
    return res;
}

std::vector<int> PmergeMe::sortVec(std::vector<int> &vec)
{
    if (vec.size() <= 1) return vec;

    int mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    left = sortVec(left);
    right = sortVec(right);

    return mergeVec(left, right); 
}

void PmergeMe::executer(int ac, char **av)
{
    if (validateAndFill(ac, av))
        return ;
    std::cout << "Vector container before sorting: " << std::endl;
    printContainer(vec);
    std::cout << "List container before sorting: " << std::endl;
    printContainer(lst);
    std::cout << "Vector container after sorting: " << std::endl;
    std::vector<int> sortedVec = sortVec(vec);
    printContainer(sortedVec);
    std::cout << "List container after sorting: " << std::endl;
    std::list<int> sortedLst = sortLst(lst);
    printContainer(sortedLst);
}
