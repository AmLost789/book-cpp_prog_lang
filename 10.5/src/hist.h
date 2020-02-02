#ifndef HIST_H_
#define HIST_H_

#include <cstdint>
#include <vector>
#include <stdexcept>

class Hist
{
public:
	Hist(uint8_t min, uint8_t max, uint8_t bins);

	void Add(uint8_t val);
	void Print(void);
private:
	std::vector<uint8_t> vect;
	uint8_t min, max, bins;
};

#endif /* HIST_H_ */
