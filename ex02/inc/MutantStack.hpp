#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &stack) : std::stack<T, container>(stack) {}
		MutantStack	&operator=(const MutantStack &stack)
		{
			if (this != &stack)
				std::stack<T, container>::operator=(stack);
			return (*this);
		}

		typedef typename container::iterator	iterator;
		typedef typename container::const_iterator	const_iterator;
		
		/* -- iterator -- */
		iterator	begin() { return (this->c.begin()); }
		iterator	end() { return (this->c.end()); }

		/* -- const_iterator -- */
		const_iterator	begin() const { return (this->c.begin()); }
		const_iterator	end() const { return (this->c.end()); }
};

#endif