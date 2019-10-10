#include <iostream>
#include <string>

struct ExampleException
{
	std::string str;
};

void f(void)
{
	std::cout << "f: start\n";
	ExampleException ex_exception;
	ex_exception.str = "Example exception!";
	throw ex_exception;

	// NOTE: THIS DOESNT' GET PRINTED SINCE THE THROW BREAKS CONTROL FLOW
	// AND CAUSES FUNCTION EXIT.
	std::cout << "f: end\n";
}

int main()
{
	try
	{
		f();
	}
	catch (ExampleException& e)
	{
		std::cout << "main: " << e.str;
	}

	return 0;
}

