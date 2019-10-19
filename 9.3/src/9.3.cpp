
#include <iostream>
#include <fstream>
#include <set>

// NOTE: have to protect against cyclic includes.  For example, the following
// include structure in the standard library results in an infinite loop.
//     bits/c++config.h
//		exception
//			bits/exception.h
//			bits/c++config.h
//
// Design decision made to only iterate into an include file if it hasn't already
// been traversed.  It will still be listed, but marked "*" to identify that it
// has already been included.
std::set<std::string> file_list;

void Find_includes(std::string file_name, std::string lvl)
{
	std::ifstream fin;
	fin.open(file_name);

	if (fin.is_open())
	{
		std::string fin_word;
		while (!fin.eof())
		{
			fin >> fin_word;

			if (fin_word.compare("#include") == 0)
			{
				// Read the next work - assume not EOF.
				fin >> fin_word;

				size_t open_bracket  = fin_word.find_first_of('<');
				size_t close_bracket = fin_word.find_first_of('>');

				// Include is standard header ?
				if ((open_bracket  != std::string::npos) &&
					(close_bracket != std::string::npos) )
				{
					std::string sub_include = "C:/MinGW/lib/gcc/mingw32/8.2.0/include/c++/";
					sub_include += fin_word.substr(open_bracket + 1, close_bracket - open_bracket - 1);

					// Call function recursively to find sub-includes if not already traversed.
					if (file_list.insert(sub_include).second)
					{
						std::cout << lvl << sub_include << std::endl;
						Find_includes(sub_include, lvl + "    ");
					}
					else
					{
						std::cout << "*" << lvl.substr(0, lvl.length() - 1) << sub_include << std::endl;
					}
				}
			}
		}
	}
}

int main()
{
	Find_includes("src/src.txt",  "");
	return 0;
}
