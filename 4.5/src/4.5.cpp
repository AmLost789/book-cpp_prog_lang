#include <iostream>
#include <limits>

int main()
{
	std::cout << "char\n";
	std::cout << "  min: " << int(std::numeric_limits<signed char>::min()) << "\n";
	std::cout << "  max: " << int(std::numeric_limits<signed char>::max()) << "\n";
	std::cout << "short\n";
	std::cout << "  min: " << std::numeric_limits<short int>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<short int>::max() << "\n";
	std::cout << "int\n";
	std::cout << "  min: " << std::numeric_limits<signed int>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<signed int>::max() << "\n";
	std::cout << "long\n";
	std::cout << "  min: " << std::numeric_limits<long int>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<long int>::max() << "\n";
	std::cout << "float\n";
	std::cout << "  min: " << std::numeric_limits<float>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<float>::max() << "\n";
	std::cout << "double\n";
	std::cout << "  min: " << std::numeric_limits<double>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<double>::max() << "\n";
	std::cout << "long double\n";
	std::cout << "  min: " << std::numeric_limits<long double>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<long double>::max() << "\n";
	std::cout << "unsigned\n";
	std::cout << "  min: " << std::numeric_limits<unsigned int>::min() << "\n";
	std::cout << "  max: " << std::numeric_limits<unsigned int>::max() << "\n";

	return 0;
}
