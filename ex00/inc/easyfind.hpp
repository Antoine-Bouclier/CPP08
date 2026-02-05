#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("No occurence found.");
		}
};

template <typename T>
typename T::const_iterator	easyfind(const T &container, int value)
{
	typename T::const_iterator	it;

	it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw	NoOccurenceFoundException();
	return (it);
}

#endif