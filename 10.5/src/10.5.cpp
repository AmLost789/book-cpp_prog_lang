#include <iostream>

#include "hist.h"

int main()
{
	Hist dog_age = Hist(0, 20, 10);

	uint16_t x;
	while(std::cin >> x)
	{
		dog_age.Add(x);
	}

	dog_age.Print();

	return 0;
}
