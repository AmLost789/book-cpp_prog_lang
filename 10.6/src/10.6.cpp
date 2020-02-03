#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

#include "RandLin.h"
#include "RandUniform.h"

#define DIST_MIN 1
#define DIST_MAX 25

#define DIST_ELEM_CNT 10000000

int main()
{
	std::vector<uint8_t> rand_vect;

	// Make the RNG.
//	RandUniform rng(DIST_MIN, DIST_MAX);
	RandLin     rng(DIST_MIN, DIST_MAX);

	// Get 1000 samples of the RNG.
	for (uint32_t i = 0; i < DIST_ELEM_CNT; i++)
	{
		rand_vect.push_back(rng.draw());
	}

	// Determine the RNG distribution.
	std::array<uint32_t, DIST_MAX - DIST_MIN + 1> dist;
	std::fill(dist.begin(), dist.end(), 0);
	for (uint8_t i : rand_vect)
	{
		dist[i - DIST_MIN]++;
	}

	// Print the RNG distribution.
	for (uint8_t i = 0; i < (DIST_MAX - DIST_MIN + 1); i++)
	{
		std::cout << std::to_string(i + DIST_MIN) << ": " << dist[i] << std::endl;
	}

	return 0;
}
