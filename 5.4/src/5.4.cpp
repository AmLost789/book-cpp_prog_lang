#include "iostream"

void swap1(int* x1, int* x2);
void swap2(int& x1, int& x2);

void printVal(int x1, int x2);



int main()
{
	int x1 = 2;
	int x2 = 5;

	printVal(x1, x2);	// Original.
	swap1(&x1, &x2);
	printVal(x1, x2);	// Swapped.
	swap2(x1, x2);
	printVal(x1, x2);	// Swapped back to original.

	return 0;
}


void swap1(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

void swap2(int& x1, int& x2)
{
	int tmp = x1;
	x1 = x2;
	x2 = tmp;
}

void printVal(int x1, int x2)
{
	std::cout << "x1: " << x1 << ", x2: " << x2 << "\n";
}
