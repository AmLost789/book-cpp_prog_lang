#include <iostream>

int f(char*);

int main()
{
	std::cout << sizeof(bool) << "\n";
	std::cout << sizeof(char) << "\n";
	std::cout << sizeof(int) << "\n";
	std::cout << sizeof(float) << "\n";
	std::cout << sizeof(double) << "\n\n";

	std::cout << sizeof(bool*) << "\n";
	std::cout << sizeof(char*) << "\n";
	std::cout << sizeof(int*) << "\n";
	std::cout << sizeof(float*) << "\n";
	std::cout << sizeof(double*) << "\n";
	std::cout << sizeof(&f) << "\n\n";

	enum Beer { Bud = -7, Coors = 0, Surly = 7 };
	enum Flowers { Rose = 0, Seedum = 512, Iris = 1024 };
	enum Cars { Ford = 60000, Chevy = 1000000, Dodge = 5000000000 };

	std::cout << sizeof(Beer) << "\n";
	std::cout << sizeof(Flowers) << "\n";
	std::cout << sizeof(Cars) << "\n";

	return 0;
}
