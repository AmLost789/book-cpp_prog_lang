#include <iostream>
#include <cstring>

void f_original(const char* input_line, unsigned int max_length)
{
	unsigned int i;
	unsigned int quest_count = 0;

	for (i = 0; i < max_length; i++)
	{
		if (input_line[i] == '?')
		{
			quest_count++;
		}
	}

	std::cout << "-- Original --" << std::endl;
	std::cout << "Count: " << quest_count << std::endl;
}

void f_while(const char* input_line, unsigned int max_length)
{
	unsigned int i;
	unsigned int quest_count = 0;

	i = 0;
	while (i < max_length)
	{
		if (input_line[i] == '?')
		{
			quest_count++;
		}

		i++;
	}

	std::cout << "-- While Loop --" << std::endl;
	std::cout << "Count: " << quest_count << std::endl;
}

void f_pointer(const char* input_line, unsigned int max_length)
{
	unsigned int quest_count = 0;

	const char* p = &input_line[0];
	while (p < &input_line[max_length])
	{
		if (*p == '?')
		{
			quest_count++;
		}

		p++;
	}

	std::cout << "-- Pointer --" << std::endl;
	std::cout << "Count: " << quest_count << std::endl;
}

int main()
{
	const char* str = "?? Is ? this ? Working ??";

	std::cout << "Test string: \"" << str << "\"" << std::endl;
	std::cout << std::endl;
	f_original(str, strlen(str));
	std::cout << std::endl;
	f_while(str, strlen(str));
	std::cout << std::endl;
	f_pointer(str, strlen(str));

	return 0;
}
