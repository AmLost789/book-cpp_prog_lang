#include <iostream>
#include "string.h"

void f1(std::string str)
{
	unsigned int count = 0;
	size_t pos = 0;

	while ((pos = str.find("ab", pos)) != std::string::npos)
	{
		count++;
		pos++;
	}

	std::cout << "C++ String Count: " << count << "\n\n";
}

void f2(const char* str)
{
	unsigned int count = 0;

	for(const char* pos = &str[0]; ; pos++)
	{
		pos = strstr(pos, "ab");
		if  (pos == NULL)
		{
			break;
		}
		else
		{
			count++;
		}
	}

	std::cout << "C String Count: " << count << "\n\n";
}

int main()
{

	std::string str = "abcde;alsjdababsldjab";		// 4 occurences of "ab".

	f1(str);
	f2(str.c_str());

	return 0;
}
