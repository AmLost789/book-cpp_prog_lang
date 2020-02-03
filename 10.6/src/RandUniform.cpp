
#include <cstdlib>
#include <exception>
#include <iostream>

#include "RandUniform.h"

RandUniform::RandUniform(uint8_t min, uint8_t max)
{
	if (min > max)
	{
		throw std::invalid_argument("min > max");
	}

	this->min = min;
	this->max = max;
}

uint8_t RandUniform::draw(void)
{
	return (rand() % (max - min + 1)) + min;
}
