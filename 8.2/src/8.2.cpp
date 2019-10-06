#include <cstdio>
#include <cstdarg>

// @see https://stackoverflow.com/questions/7188069/problem-wrapping-extern-c-library-in-a-namespace
// - I don't have a library I've used previously which I can modify the header files of, as is
//   described in section 8.2.9.  Therefore, I'm trying the approach of wrapping a standard library
//   function in a namespace.
// @see https://stackoverflow.com/questions/3530771/passing-variable-arguments-to-another-function-that-accepts-a-variable-argument
namespace cstdio_namespace
{
	int printf(const char * fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		int ret_val = vprintf(fmt, args);
		va_end(args);

		return ret_val;
	}
}

int main()
{
	cstdio_namespace::printf("This Works!");
	return 0;
}
