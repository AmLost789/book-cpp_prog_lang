#ifndef RANDLIN_H_
#define RANDLIN_H_

#include <cstdint>

class RandLin
{
	uint8_t min, max;

public:
	RandLin(uint8_t min, uint8_t max);
	uint8_t draw(void);
};

#endif /* RANDLIN_H_ */
