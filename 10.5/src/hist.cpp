#include <exception>
#include <iostream>
#include <string>

#include "hist.h"

typedef struct
{
	uint8_t min;
	uint8_t max;
	uint8_t cnt;
} BIN_S;

Hist::Hist(uint8_t min, uint8_t max, uint8_t bins)
{
	if (max <= min)
	{
		throw std::invalid_argument("min >= max");
	}

	if ((max - min) % bins != 0)
	{
		throw std::invalid_argument("Cannot divide into even bins");
	}

	this->min = min;
	this->max = max;
	this->bins = bins;
}

void Hist::Add(uint8_t val)
{
	if ((min <= val) && (val < max))	// Histo lower bound inclusive, higher bound exclusive.
	{
		vect.push_back(val);
	}
	else
	{
		throw std::out_of_range("Value not within histogram range. min: " + std::to_string(min) + ", max:" + std::to_string(max));
	}
}

void Hist::Print(void)
{
	// Determine the bins.
	std::vector<BIN_S> bin_vect;
	uint8_t bin_min = min;
	uint8_t bin_interval = (max - min) / bins;
	while (bin_min < max)
	{
		BIN_S bin;
		bin.min = bin_min;
		bin.max = bin_min + bin_interval;
		bin.cnt = 0;
		bin_vect.push_back(bin);

		bin_min += bin_interval;
	}

	// Determine vector allocation in bins.
	for (uint8_t val : vect)
	{
		for (BIN_S& bin : bin_vect)
		{
			if ((bin.min <= val) && (val < bin.max))	// Histo lower bound inclusive, higher bound exclusive.
			{
				std::cout << "increment";
				bin.cnt++;
			}
		}
	}

	// Print the histogram.
	printf("\n\n");
	for (BIN_S bin : bin_vect)
	{
		std::cout << std::to_string(bin.min) << "-" << std::to_string(bin.max) << ": " << std::to_string(bin.cnt) << std::endl;
	}
}
