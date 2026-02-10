#include "Span.hpp"

/* -- Constructors -- */
Span::Span() : _d(), _size(0), _smallest(0), _biggest(0)
{
}

Span::Span(unsigned int N) : _d(), _size(N), _smallest(N), _biggest(N)
{
}


Span::Span(const Span &copy) : _d(copy._d), _size(copy._size), _smallest(copy._smallest), _biggest(copy._biggest)
{
}

Span	&Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_d = copy._d;
		this->_size = copy._size;
		this->_smallest = copy._smallest;
		this->_biggest = copy._biggest;
	}
	return (*this);
}


Span::~Span()
{
}

/* -- Member function -- */
void	Span::addNumber(int number)
{
	if (this->_d.size() >= this->_size)
		throw NoSpaceException();
	this->_d.push_back(number);
	if (this->_d.size() == 1)
	{
		this->_smallest = number;
		this->_biggest = number;
	}
	else
	{
		setBiggest(number);
		setSmallest(number);
	}
}

void	Span::addNumbers(int first, int last)
{
	(void)first;
	(void)last;
}

void	Span::setSmallest(int number)
{
	if (this->_smallest > number)
		this->_smallest = number;
}

void	Span::setBiggest(int number)
{
	if (this->_biggest < number)
		this->_biggest = number;
}

unsigned int	Span::shortestSpan()
{
	return (1);
}

unsigned int	Span::longestSpan()
{
	if (this->_d.size() < 2)
		throw NoNumberStoredException();
	return (this->_biggest - this->_smallest);
}

/* -- Exceptions -- */
const char* Span::NoNumberStoredException::what() const throw()
{
	return ("No number are store.");
}

const char* Span::NoSpaceException::what() const throw()
{
	return ("No more space.");
}