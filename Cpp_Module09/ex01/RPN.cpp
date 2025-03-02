#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &cpy)
{
    if (this != &cpy)
    {
        this->stack = cpy.stack;
    }
}

RPN &RPN::operator=(const RPN &copy)
{
    (void)copy;
    return *this;
}

int RPN::calculate(char c)
{
    if (stack.size() < 2)
    {
        std::cerr << "Error: Program requires at least 2 numbers." << std::endl;
        return 1;
    }
    int temp_num = stack.top();
    stack.pop();
    int temp_num2 = stack.top();
    return (c == '+') ? (stack.pop(), stack.push(temp_num2 + temp_num), 0) :
           (c == '-') ? (stack.pop(), stack.push(temp_num2 - temp_num), 0) :
           (c == '/') ? (temp_num == 0 ? (std::cerr << "Error: Division by zero is not allowed." << std::endl, 1) : (stack.pop(), stack.push(temp_num2 / temp_num), 0)) :
           (c == '*') ? (stack.pop(), stack.push(temp_num2 * temp_num), 0) :
           (std::cerr << "Error: Program handles only '+', '-', '/' and '*' operators." << std::endl, 1);
}


void RPN::executer(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == ' ')
            continue;
        else if (str[i] >= '0' && str[i] <= '9')
            stack.push(str[i] - '0');
        else if (stack.size() >= 2 && calculate(str[i]))
                return ;
    }
    if (stack.size() != 1)
    {
        std::cout << "Error: After the calculation there are more than one number." << std::endl;
        return ;
    }
    std::cout << stack.top() << std::endl;
}