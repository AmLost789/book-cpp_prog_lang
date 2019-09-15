
#include <iostream>
#include <string>

int main()
{
	char char_str[] = "a short string";

	std::cout << "str[] size: " << sizeof(char_str) << "\n\n";

	std::string str_str = "a short string";

	std::cout << "str[] size: " << str_str.length() << "\n\n";


	// SIZE OF 'char_str' IS ONE LARGER BECAUSE OF NULL TERMINATION.


	return 0;
}
