#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN &cpy);
        RPN &operator=(const RPN &cpy);
        ~RPN();

    public:
        int calculate(char c);
        void executer(std::string str);
        
};

#endif