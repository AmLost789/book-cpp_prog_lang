#include <algorithm>
#include <iostream>
#include <string>
#include <set>

// Use the set so that duplicates are not added.
// Sorting: sets of std:string are already sorted in alphabetical ordering (i.e. on insertion)
// so no additional sorting is required.
// see:
//	- https://stackoverflow.com/questions/8833938/is-the-stdset-iteration-order-always-ascending-according-to-the-c-specificat
//  - http://www.cplusplus.com/reference/functional/less/
std::set<std::string> str_set;

void printElements(void)
{
	std::cout << "\n\nOutput:\n\n";

	for(std::set<std::string>::iterator it = str_set.begin(); it != str_set.end(); it++)
	{
		std::cout << *it << "\n";
	}
}

int main()
{
	std::string str_in;

	// Store user input until 'Quit' or array full.
	while(1)
	{
		std::cin >> str_in;

		if (str_in == "Quit")
		{
			break;
		}
		else
		{
			str_set.insert(str_in);
		}
	}

	// Print the user input.
	printElements();

	return 0;
}

