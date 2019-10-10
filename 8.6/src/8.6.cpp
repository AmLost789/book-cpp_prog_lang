#include <iostream>
#include <sstream>
#include <chrono>

void f1(unsigned int exception_depth = 100);
void f2(unsigned int exception_depth = 100);

static std::chrono::high_resolution_clock::time_point time_stamp;

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

		std::cout << std::chrono::high_resolution_clock::now().time_since_epoch().count() << " - ";
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
			std::cout << std::chrono::high_resolution_clock::now().time_since_epoch().count() << " - ";
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

		std::cout << std::chrono::high_resolution_clock::now().time_since_epoch().count() << " - ";
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
			std::cout << std::chrono::high_resolution_clock::now().time_since_epoch().count() << " - ";
			call_depth--;
			std::cout << "f1: Exception caught and re-thrown, at depth: " << call_depth << "\n";
			throw e;
		}
	}
}



// NOTE: I TRIED THIS FOR SEVERAL HOURS WITH NO AVAIL.  LOOKING THAT THE TIME-STAMP
// FROM RUNNING THE APPLICATION IDENTIFIED THAT IT'S ONLY UPDATED AT ~1MS RATE, WHICH
// IS MUCH TOO SLOW FOR TIME DIFFERENCES WE ARE TRYING TO MEASURE.  RESEARCHING ONLINE,
// IT LOOKS LIKE A DIFFERENT WINDOWS SPECIFIC TIMER WOULD LIKELY HAVE TO BE USED
// TO ACHIEVE THE PERFORMANCE WE WANT.  E.G.:
//	https://docs.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter?redirectedfrom=MSDN

int main()
{
	try
	{
		std::cout << "main: try\n";
//		f1(10);
		f2();
	}
	catch(ExampleException& e)
	{
		std::cout << "main: catch\n";
		std::cout << e.str << "\n";
	}

	std::cout << "main: end\n";

	return 0;
}


