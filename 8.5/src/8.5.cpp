#include <iostream>
#include <sstream>

void f1(unsigned int exception_depth = 100);
void f2(unsigned int exception_depth = 100);

struct ExampleException
{
	std::string str;
};

void f1(unsigned int exception_depth)
{
	static unsigned int call_depth = 0;
	call_depth++;

	std::cout << "f1: " << call_depth << "\n";
	if (call_depth >= exception_depth)
	{
		ExampleException e;

		std::stringstream sstm;
		sstm << "!!!f1() Exception String!!!";
		e.str = sstm.str();

		std::cout << "f1: Exception generated, at depth: " << call_depth << "\n";
		throw e;
	}
	else
	{
		try
		{
			f2(exception_depth);
		}
		catch(ExampleException& e)
		{
			call_depth--;
			std::cout << "f1: Exception caught and re-thrown, at depth: " << call_depth << "\n";
			throw e;
		}
	}
}

void f2(unsigned int exception_depth)
{
	static unsigned int call_depth = 0;
	call_depth++;

	std::cout << "f2: " << call_depth << "\n";
	if (call_depth >= exception_depth)
	{
		ExampleException e;

		std::stringstream sstm;
		sstm << "!!!f2() Exception String!!!";
		e.str = sstm.str();

		std::cout << "f2: Exception generated, at depth: " << call_depth << "\n";
		throw e;
	}
	else
	{
		try
		{
			f1(exception_depth);
		}
		catch(ExampleException& e)
		{
			call_depth--;
			std::cout << "f2: Exception caught and re-thrown, at depth: " << call_depth << "\n";
			throw e;
		}
	}
}

int main()
{
	try
	{
		std::cout << "main: try\n";
//		f1(10);
		f2(10);
	}
	catch(ExampleException& e)
	{
		std::cout << "main: catch\n";
		std::cout << e.str << "\n";
	}

	std::cout << "main: end\n";

	return 0;
}
