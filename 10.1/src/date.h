/*
 * data.h
 *
 *  Created on: Oct 29, 2019
 *      Author: jonrw
 */

#ifndef DATE_H_
#define DATE_H_

class Date
{
	int d, m, y;
public:
	void init(int dd, int mm, int yy);

	Date& add_year(int n);
	void add_month(int n);
	void add_day(int n);

	void print(void);
};

#endif /* DATE_H_ */
