
// This link gives a nice explanation:
// @see https://en.cppreference.com/w/cpp/preprocessor/include

// Using MinGW, so iostream stored at C:\MinGW\lib\mingw32\8.2.0\include\c++\iostream
#include <iostream>

// Added file 'amlost' to above MinGW path. I'm able to include this file using the
// angle bracket convention.
#include <amlost>

// Looking at the MinGW path it doesn't look like any non-standard includes are
// present in the directory.

int main()
{

	return 0;
}
