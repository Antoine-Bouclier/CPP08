#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		std::vector<int>		_d;
		unsigned int		_size;
		int					_smallest;
		int					_biggest;

		void	updateBounds(int number);
		void	updateBounds(int smallest, int largest);
	public:
		/* -- Constructors -- */
		Span(unsigned int N);
		Span(const Span &copy);
		Span	&operator=(const Span &copy);
		~Span();

		/* -- Member function -- */
		void			addNumber(int number);
		void			addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		/* -- Exceptions -- */
		class NoSpaceException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoNumberStoredException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif