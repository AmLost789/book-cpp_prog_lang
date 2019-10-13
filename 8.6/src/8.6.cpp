#include <iostream>
#include <sstream>
#include <chrono>

// @see: https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
#include <Windows.h> // Windows Platform SDK

_LARGE_INTEGER freq;
_LARGE_INTEGER start;
_LARGE_INTEGER finish;

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
		(void) QueryPerformanceCounter(&start);
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
			(void) QueryPerformanceCounter(&finish);
			call_depth--;
			std::cout << "f1: Exception caught and re-thrown, at depth: " << call_depth << ", time diff: " << (finish.QuadPart-start.QuadPart) << "\n";
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
		(void) QueryPerformanceCounter(&start);
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
			(void) QueryPerformanceCounter(&finish);
			call_depth--;
			std::cout << "f2: Exception caught and re-thrown, at depth: " << call_depth << ", time diff: " << (finish.QuadPart-start.QuadPart) << "\n";
			throw e;
		}
	}
}


int main()
{
	(void) QueryPerformanceFrequency(&freq);
	std::cout << "Counter Frequency: " << freq.QuadPart << " [counts/second]" << std::endl << std::endl;

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

// NOTE: Typical output shows an steady increase in exception execution time as the call
// depth decreases.  For example, with an exception thrown at a call depth of 10, exception
// execution time is ~2.02ms.  Once this exception rolls up to a call depth of 1, the
// exception execution time is ~2.09ms.
//
// I'm not sure why this is the case, but it's interesting.



