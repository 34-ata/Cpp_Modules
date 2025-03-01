#include "Span.hpp"

Span::Span() : _n(0), _vec(std::vector<int>()) {}
Span::Span(unsigned int n) : _n(n), _vec(std::vector<int>()) {}
Span::Span(Span const &other) : _n(other._n), _vec(other._vec) {}
Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n)
{
    if (_vec.size() >= _n)
        throw Span::SpanOverflowException();
    _vec.push_back(n);
}

void Span::addNumbers(unsigned int size)
{
    if (_vec.size() + size > _n)
        throw Span::SpanOverflowException();
    for (unsigned int i = 0; i < size; i++)
        _vec.push_back(i);
}

int Span::shortestSpan()
{
    if (_vec.size() <= 1)
        throw Span::SpanOverflowException();
    std::vector<int> vec = _vec;
    std::sort(vec.begin(), vec.end());
    int min = vec[1] - vec[0];
    for (size_t i = 2; i < vec.size(); i++)
    {
        if (vec[i] - vec[i - 1] < min)
            min = vec[i] - vec[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (_vec.size() <= 1)
        throw Span::SpanOverflowException();
    std::vector<int> vec = _vec;
    std::sort(vec.begin(), vec.end());
    return vec[vec.size() - 1] - vec[0];
}
