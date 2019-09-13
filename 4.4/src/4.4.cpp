#include <iostream>

int main()
{
	char val_c;

	for (val_c = 'a'; val_c <= 'z'; val_c++)
	{
		std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";

	for (val_c = '0'; val_c <= '9'; val_c++)
	{
		std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";

	val_c = '.';
	std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	val_c = '~';
	std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	val_c = ')';
	std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	val_c = '*';
	std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	val_c = '\\';
	std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";
	val_c = '^';
	std::cout << val_c << "\t" << std::dec << int(val_c) << "\t" << std::hex << int(val_c) << "\n";

	return 0;
}
