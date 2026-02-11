#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	/* -- TEST VECTOR -- */
	{
		std::vector<int>	values;

		for (int i = 0; i < 10; i++)
			values.push_back(i);
		try
		{
			std::cout << *easyfind(values, 5) << std::endl;
			std::cout << *easyfind(values, 20) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::vector<int>	v;
		v.push_back(-10);
		v.push_back(2);
		v.push_back(0);
		v.push_back(245201254);
		v.push_back(2);
		std::cout << "TEST with double occurence: " << *easyfind(v, 2) << std::endl;
		std::cout << "TEST with negative: " << *easyfind(v, -10) << std::endl;
		std::cout << "TEST with zero: " << *easyfind(v, 0) << std::endl;
		std::cout << "TEST with large number: " << *easyfind(v, 245201254) << std::endl;

		std::list<int> l;
		std::cout << "TEST with no value : ";
		try
		{
			easyfind(l, 10);
		} catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	/* -- TEST LIST -- */
	{
		std::list<int>	values;

		for (int i = 0; i < 10; i++)
			values.push_back(i);
		try
		{
			std::cout << *easyfind(values, 5) << std::endl;
			std::cout << *easyfind(values, 20) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	/* -- TEST DEQUE -- */
	{
		std::deque<int>	values;

		for (int i = 0; i < 10; i++)
			values.push_back(i);
		try
		{
			std::cout << *easyfind(values, 5) << std::endl;
			std::cout << *easyfind(values, 20) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}