/*
 * data.h
 *
 *  Created on: Jan 5, 2020
 *      Author: jonrw
 */

#ifndef DATE_H_
#define DATE_H_

namespace Chrono
{
	class Date
	{
		int d, m, y;
		static Date default_date;

	public:
		Date(int dd=0, int mm=0, int yy=0);

		int day(void);
		int month(void);
		int year(void);

		static void set_default(int dd, int mm, int yy);
	};
}


#endif /* DATE_H_ */
