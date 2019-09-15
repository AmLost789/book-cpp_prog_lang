
#include <iostream>
using namespace std;

const int MONTHS = 12;

void alg1(void)
{
	const char* month[MONTHS] =
	{
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"Jun",
		"Jul",
		"Aug",
		"Sep",
		"Oct",
		"Nov",
		"Dec",
	};


	const unsigned int days[MONTHS] =
	{
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31,
	};


	for (unsigned int i = 0; i < MONTHS; i++)
	{
		cout << "month: " << month[i] << ", days: " << days[i] << "\n";
	}

}

void alg2(void)
{
	struct month_data
	{
		const char* month;
		unsigned int days;
	};

	const month_data md[MONTHS] =
	{
		{ "Jan", 31, },
		{ "Feb", 28, },
		{ "Mar", 31, },
		{ "Apr", 30, },
		{ "May", 31, },
		{ "Jun", 30, },
		{ "Jul", 31, },
		{ "Aug", 31, },
		{ "Sep", 30, },
		{ "Oct", 31, },
		{ "Nov", 30, },
		{ "Dec", 31, },
	};

	for (unsigned int i = 0; i < MONTHS; i++)
	{
		cout << "month: " << md[i].month << ", days: " << md[i].days << "\n";
	}
}


int main()
{
	cout << "=== Algorithm 1 ===\n";
	alg1();

	cout << "\n\n";
	cout << "=== Algorithm 2 ===\n";
	alg2();

	return 0;
}
