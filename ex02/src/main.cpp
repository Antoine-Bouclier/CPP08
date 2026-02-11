#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	/* -- TEST with MutantStack -- */
	{
		std::cout << "TEST MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "value on top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size of the stack: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << std::endl;

		/* -- iterator -- */
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "iterator: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		/* -- const iterator -- */
		MutantStack<int>::const_iterator	cit = mstack.begin();
		MutantStack<int>::const_iterator	cite = mstack.end();
		std::cout << "const_iterator: ";
		while (cit != cite)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;

		/* -- Test copy -- */
		MutantStack<int>	copy(mstack);
		std::cout << "\ntest copy: " << std::endl;
		copy.pop();
		std::cout << "size of mstack: " << mstack.size() << std::endl;
		std::cout << "size of copy: " << copy.size() << std::endl;
		std::cout << std::endl;

		copy = mstack;
		std::cout << "size of mstack: " << mstack.size() << std::endl;
		std::cout << "size of copy: " << copy.size() << std::endl;
		std::cout << std::endl;
	}

	/* -- TEST with list -- */
	{
		std::cout << "TEST LIST" << std::endl;
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << "value on top: " << l.back() << std::endl;
		l.pop_back();
		std::cout << "size of the list: " << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		l.push_back(0);
		std::cout << std::endl;

		/* -- iterator -- */
		std::cout << "iterator: ";
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << " ";
		++it;
		}
		std::cout << std::endl;

		/* -- const iterator -- */
		std::cout << "const_iterator: ";
		std::list<int>::const_iterator	cit = l.begin();
		std::list<int>::const_iterator	cite = l.end();
		while (cit != cite)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;
	}
	return 0;
}