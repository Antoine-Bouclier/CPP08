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
	updateBounds(number);
}

void	Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	unsigned int	dist = std::distance(first, last);

	if (this->_d.size() + dist > this->_size)
		throw	NoSpaceException();
	else
	{
		this->_d.insert(this->_d.end(), first, last);
		std::vector<int>	tmp(this->_d);
		std::sort(tmp.begin(), tmp.end());
		updateBounds(tmp.front(), tmp.back());
	}
}

void	Span::updateBounds(int number)
{
	if (this->_d.size() == 1)
	{
		this->_smallest = number;
		this->_biggest = number;
	}
	else
	{
		this->_smallest = std::min(this->_smallest, number);
		this->_biggest = std::max(this->_biggest, number);
	}
}

void	Span::updateBounds(int smallest, int longest)
{
	if (this->_d.size() == 1)
	{
		this->_smallest = smallest;
		this->_biggest = longest;
	}
	else
	{
		this->_smallest = std::min(this->_smallest, smallest);
		this->_biggest = std::max(this->_biggest, longest);
	}
}

unsigned int	Span::shortestSpan()
{
	if (this->_d.size() < 2)
		throw NoNumberStoredException();
	std::vector<int>	tmp(this->_d);
	std::sort(tmp.begin(), tmp.end());
	unsigned int	shortest = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); ++i)
	{
		unsigned int	diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
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