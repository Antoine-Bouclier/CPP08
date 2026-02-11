#include "Span.hpp"

int	main(void)
{
	try
	{
		std::cout << "TEST basic" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		Span sp = Span(5);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Empty span test: " << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		Span sp = Span(5);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Single element test: " << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "TEST Overflow" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(22); // throw exception
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "TEST negative" << std::endl;
		Span sp = Span(6);
		sp.addNumber(-10);
		sp.addNumber(0);
		sp.addNumber(10);
		sp.addNumber(-5);
		sp.addNumber(5);
		sp.addNumber(20);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 5
		std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 30
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "TEST large number" << std::endl;
		Span sp = Span(3);
		sp.addNumber(1000000);
		sp.addNumber(5000000);
		sp.addNumber(3000000);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 2000000
		std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 4000000
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "TEST range of iterator" << std::endl;
		Span	sp = Span(1500);
		std::vector<int>		test;
		for (int i = 0; i < 1500; i++)
			test.push_back(i * 10);
		sp.addNumbers(test.begin(), test.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "TEST range of iterator overflow" << std::endl;
		Span	sp = Span(15);
		std::vector<int>		test;
		for (int i = 0; i < 16; i++)
			test.push_back(i * 10);
		sp.addNumbers(test.begin(), test.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "TEST copy" << std::endl;
		Span sp = Span(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		Span	copy(sp);
		sp.addNumber(21);
		std::cout << "Original Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Original Longest: " << sp.longestSpan() << std::endl;
		std::cout << "Copy Shortest: " << copy.shortestSpan() << std::endl;
		std::cout << "Copy Longest: " << copy.longestSpan() << std::endl;
		std::cout << std::endl;

		sp = copy;
		std::cout << "BEFORE :" << std::endl;
		std::cout << "Original Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Original Longest: " << sp.longestSpan() << std::endl;
		std::cout << "Copy Shortest: " << copy.shortestSpan() << std::endl;
		std::cout << "Copy Longest: " << copy.longestSpan() << std::endl;
		sp.addNumber(21);
		std::cout << "AFTER :" << std::endl;
		std::cout << "Original Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Original Longest: " << sp.longestSpan() << std::endl;
		std::cout << "Copy Shortest: " << copy.shortestSpan() << std::endl;
		std::cout << "Copy Longest: " << copy.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	

	return 0;
}