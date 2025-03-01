#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
	
    public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

    public:
		void addNumber(int n);
        void addNumbers(unsigned int size);
		int shortestSpan();
		int longestSpan();
		class SpanOverflowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Span's capacity is full, no more elements can be added.";
				}
		};
};

#endif