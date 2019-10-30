
#include "date.h"

int main(void)
{
	Date d1;
	d1.init(29, 10, 2019);

	d1.add_year(10);
	d1.print();

	return 0;
}


/*
ANSWERS:

Issue from section 10.2.2: is that the add_year function cannot
be defined inline since it definition must be visible to its
usage - i.e. 'main' from above must have visibility to the 'add_year'
definition which is in date.cpp.  The function 'add_year' needs to not
be define inline, or the function definition needs to be moved to the
header file - which not longer 'hides' the implementation from the
user, which is the point of modularity and encapsulation.





Issue for section 10.2.7: I'm not as sure about this one.  Immediately
there is not definition for function 'leapyear' and therefore yields
compilation issues.  I resolved this by addition a definition.

Secondly, I think the chaining of functions can have unexpected results
depending on the order of operations.  For example, with a date of
Feb 29, 2020; the following produces:

d1.add_day(1).add_year(1) = March 1, 2021
d1.add_year(1).add_day(1) = March 2, 2021

A better design would likely be to have a single function with default
parameters, e.g.

Date::add(int d, int m=0, int y=0)

*/
