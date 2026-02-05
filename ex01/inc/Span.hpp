#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
private:
	
public:
	/* -- Constructors -- */
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	Span	&operator=(const Span &copy);
	~Span();

	/* -- Member function -- */
	void	addNumber(unsigned int number);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	/* -- Exceptions -- */
	class NoSpaceException : public std::exception
	{
		public:
			virtual const char *what() throw();
	};

	class NoNumberStoredException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif