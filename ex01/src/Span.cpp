#include "Span.hpp"

/* -- Constructors -- */
template <typename T>
Span<T>::Span() : _array(NULL), _size(0)
{
}
template <typename T>
Span<T>::Span(unsigned int N) : _array(new T[N]), _size(N)
{

}

template <typename T>
Span<T>::Span(const Span &copy) : _array(new T[copy._size]), _size(copy._size)
{
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_array[i] = copy._array[i];
	}
}
template <typename T>
T	&Span<T>::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_size = copy._size;
		delete[] this->_array;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = copy._array[i];
		}
	}
	return (*this);
}

template <typename T>
Span<T>::~Span()
{
}

/* -- Member function -- */
template <typename T>
void	Span<T>::addNumber(unsigned int number)
{

}

template <typename T>
unsigned int	Span<T>::shortestSpan()
{

}

template <typename T>
unsigned int	Span<T>::longestSpan()
{

}
