#include "date.h"

using Chrono::Date;

Date::Date(int dd, int mm, int yy)
{
	d = (dd==0) ? default_date.day() : dd;
	m = (mm==0) ? default_date.month() : mm;
	y = (yy==0) ? default_date.year() : yy;
}

int Date::day(void)
{
	return d;
}

int Date::month(void)
{
	return m;
}

int Date::year(void)
{
	return y;
}


Date Date::default_date(16, 12, 1770);

void Date::set_default(int dd, int mm, int yy)
{
	default_date = Date(dd, mm, yy);
}
