#include "easyfind.hpp"
#include <vector>

int	main(void)
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
	
}