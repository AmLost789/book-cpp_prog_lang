
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

#include "trim.h"

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

// Note: all the below tests have many assumptions - e.g. character '//' is not
// part of string literal definition.  Assumptions made since I'm not implementing a
// full fledged C-language parser.
bool Comment_test(std::string file_ln)
{
	static bool comment_active = false;
	bool comment_line = false;

	// First character in line is '//' ?
	if (ltrim_copy(file_ln).find("//") == 0)
	{
		comment_line = true;
	}

	// Continuation of "/* */" comment block ?
	if (comment_active == true)
	{
		comment_line = true;
	}

	// '/*' occurs in line ?
	if (file_ln.find("/*") != std::string::npos)
	{
		comment_active = true;
		comment_line = true;
	}

	// if '*/' occurs in the line then this is the end of a comment.
	if (file_ln.find("*/") != std::string::npos)
	{
		comment_active = false;
	}

	return comment_line;
}

void Find_includes(std::string file_name, std::string lvl)
{
	std::set<std::pair<std::string,std::string>> include_list;

	uint32_t cmt_cnt = 0;
	uint32_t non_cmt_cnt = 0;
	uint32_t non_cmt_word_cnt = 0;

	std::ifstream fin;
	fin.open(file_name);

	if (fin.is_open())
	{
		std::string file_ln;

		while (std::getline(fin, file_ln))
		{
			// Evaluate comments.
			if (Comment_test(file_ln))
			{
				cmt_cnt++;
			}
			else
			{
				non_cmt_cnt++;

				// Count the number of whitespace separated words in the line.
				std::string ln_word;
			    std::stringstream ss(file_ln);
			    while (ss >> ln_word)
			    {
			        non_cmt_word_cnt++;
			    }
			}

			// Evaluate "#include" directives.
			if (file_ln.find("#include") != std::string::npos)
			{
				size_t open_bracket  = file_ln.find('<');
				size_t close_bracket = file_ln.find('>');

				// Include is standard header ?
				if ((open_bracket  != std::string::npos) &&
					(close_bracket != std::string::npos) )
				{
					std::string sub_include = "C:/MinGW/lib/gcc/mingw32/8.2.0/include/c++/";
					sub_include += file_ln.substr(open_bracket + 1, close_bracket - open_bracket - 1);

					// Call function recursively to find sub-includes if not already traversed.
					if (file_list.insert(sub_include).second)
					{
						include_list.insert(std::pair<std::string,std::string>(sub_include, lvl + "    "));
					}
				}
			}
		}

		// Print the file name.
		std::cout << lvl << file_name << " (cmt: " << cmt_cnt << ", non-cmt: " << non_cmt_cnt << ", non-cmt words: " << non_cmt_word_cnt << ")"<< std::endl;

		// Recursively call includes.
		std::set<std::pair<std::string,std::string>> :: iterator itr;
		for (itr = include_list.begin(); itr != include_list.end(); itr++)
		{
			Find_includes(itr->first, itr->second);
		}
	}
}

int main()
{
	Find_includes("src/src.txt",  "");
	return 0;
}
