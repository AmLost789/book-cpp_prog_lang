
// @see: https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
#include <Windows.h> // Windows Platform SDK

#include <iostream>

int f(bool throw_val)
{
	if (throw_val)
	{
		throw int(311);
	}

	return 42;
}

int main()
{
	_LARGE_INTEGER freq;
	_LARGE_INTEGER start;
	_LARGE_INTEGER finish;

	(void) QueryPerformanceFrequency(&freq);
	std::cout << "Counter Frequency: " << freq.QuadPart << " [counts/second]" << std::endl << std::endl;

	(void) QueryPerformanceCounter(&start);
	(void) f(false);
	(void) QueryPerformanceCounter(&finish);
	std::cout << "Returned Value. Execution time:" << (finish.QuadPart-start.QuadPart) << std::endl;

	try
	{
		(void) QueryPerformanceCounter(&start);
		(void) f(true);
	}
	catch(int& e)
	{
		(void) QueryPerformanceCounter(&finish);
		std::cout << "Returned Exception. Execution time:" << (finish.QuadPart-start.QuadPart) << std::endl;
	}

	return 0;
}

/*
NOTES: HOLLY COW!!! Application output is:

	Counter Frequency: 10000000 [counts/second]

	Returned Value. Execution time:2
	Returned Exception. Execution time:20792

Therefore, when the error isn't throws the function takes 0.2us.  When an error is thrown
the function takes 2.08ms - 4 orders of magnitude more.  I knew exceptions were more, but
I didn't expect by this large degree.  This strengthens the fact that exceptions should
only be used for abnormal (i.e. atypical) operation.
*/


