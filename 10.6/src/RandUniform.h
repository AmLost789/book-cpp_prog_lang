/*
 * RandUniform.h
 *
 *  Created on: Feb 2, 2020
 *      Author: jonrw
 */

#ifndef RANDUNIFORM_H_
#define RANDUNIFORM_H_

#include <cstdint>

class RandUniform
{
	uint8_t min, max;

public:
	RandUniform(uint8_t min, uint8_t max);
	uint8_t draw(void);
};

#endif /* RANDUNIFORM_H_ */
