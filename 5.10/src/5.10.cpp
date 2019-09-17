#include <iostream>
using namespace std;

const unsigned int MONTHS = 12;

void f(const char* m[], unsigned int m_len)
{
	cout << "-- f --\n";
	for (unsigned int i = 0; i < m_len; i++)
	{
		cout << m[i] << "\n";
	}
}

int main()
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

	cout << "-- Main --\n";
	for (unsigned int i = 0; i < MONTHS; i++)
	{
		cout << month[i] << "\n";
	}
	cout << "\n";

	f(&month[0], MONTHS);

	return 0;
}
