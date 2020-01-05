//// METHOD #1
//#include <iostream>
//#include "date.h"
//int main()
//{
//	Chrono::Date::set_default(1, 1, 2001);
//	Chrono::Date tmp = Chrono::Date();
//	std::cout << "d: " << tmp.day() << ", m: " << tmp.month() << ", y: " << tmp.year() << std::endl;
//
//	return 0;
//}

//// METHOD #2
//#include <iostream>
//#include "date.h"
//using namespace Chrono;
//int main()
//{
//	Date::set_default(2, 2, 2002);
//	Date tmp = Date();
//	std::cout << "d: " << tmp.day() << ", m: " << tmp.month() << ", y: " << tmp.year() << std::endl;
//
//	return 0;
//}

// METHOD #3
#include <iostream>
#include "date.h"
using Chrono::Date;
int main()
{
	Date tmp;
	tmp.set_default(3, 3, 2003);
	tmp = Date();

	std::cout << "d: " << tmp.day() << ", m: " << tmp.month() << ", y: " << tmp.year() << std::endl;

	return 0;
}
