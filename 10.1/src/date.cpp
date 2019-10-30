
#include <iostream>

#include "date.h"

void Date::init(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}

bool leapyear(int n)
{
	bool leap = false;

	// Leap every 4 years.
	if ((n % 4) == 0)
	{
		// Unless you're divisable by 100.
		if ((n % 100) == 0)
		{
			// Except if divisable by 400.
			if ((n % 400) == 0)
			{
				leap = true;
			}
		}
		else
		{
			leap = true;
		}
	}

	return leap;
}

Date& Date::add_year(int n)
{
	if (d==29 && m==2 && !leapyear(y+n))	// beware of February 29
	{
		 d = 1;
		 m = 3;
	}
	y += n;
	return *this;
}

void Date::print(void)
{
	std::cout << "dd/mm/yyyy: " << d << "/" << m << "/" << y;
}



