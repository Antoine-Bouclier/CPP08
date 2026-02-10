#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <deque>

class Span
{
	private:
		std::deque<int>		_d;
		unsigned int		_size;
		int					_smallest;
		int					_biggest;
	public:
		/* -- Constructors -- */
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span	&operator=(const Span &copy);
		~Span();

		/* -- Member function -- */
		void			addNumber(int number);
		void			addNumbers(int first, int last);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		/* -- Setters -- */
		void	setSmallest(int number);
		void	setBiggest(int number);

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