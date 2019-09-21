#include <iostream>

struct Date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

Date readDate(void)
{
	std::cout << "Input date: year month day: ";

	Date d;
	std::cin >> d.year;
	std::cin >> d.month;
	std::cin >> d.day;

	return d;
}

void writeDate(const Date& d)
{
	std::cout << "\nDate: year=" << d.year << ", month=" << d.month << ", day=" << d.day << "\n";
}

void initDate(Date* d1, const Date& d2)
{
	*d1 = d2;
}

int main()
{
	Date d1 = readDate();
	writeDate(d1);

	Date d2 = { .year = 1986, .month = 5, .day = 26};
	Date d3;
	initDate(&d3, d2);
	writeDate(d3);

	return 0;
}
