
#include <cstdlib>
#include <exception>
#include <iostream>
#include <cmath>

#include "RandLin.h"

RandLin::RandLin(uint8_t min, uint8_t max)
{
	if (min > max)
	{
		throw std::invalid_argument("min > max");
	}

	this->min = min;
	this->max = max;
}

uint8_t RandLin::draw(void)
{
	// Example:
	//	min = 2
	//	max = 4
	//	min_2 = 4
	//	max_2 = 24
	//  result = [4, 24]
	//	result = [2, sqrt(24) = 4.89]
	//	result = [2, 3, 4]

	uint16_t min_2 = std::round(std::pow(min, 2));							//std::cout << min_2 << std::endl;
	uint16_t max_2 = std::round(std::pow(max + 1, 2) - 1);		//std::cout << max_2 << std::endl;

	uint16_t result = (rand() % (max_2 - min_2 + 1)) + min_2;	// std::cout << result << " ";
	result = std::sqrt(result);									// std::cout << result << std::endl;

	return static_cast<uint8_t>(result);
}
