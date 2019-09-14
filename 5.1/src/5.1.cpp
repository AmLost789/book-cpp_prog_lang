#include <iostream>
#include <string>

// a pointer to a character
char char_v = 'a';
const char* char_p = &char_v;

// an array of 10 integers
int int_arr[10] = { 0 };

// a reference to an array of 10 integers
int (&int_arr_ref)[10] = int_arr;

// a pointer to an array of character strings
std::string str_arr[] = { "Yes", "No", "Maybe" };
std::string* char_str_arr_p = str_arr;

// a pointer to a pointer to a character
const char** char_pp = &char_p;

// a constant integer
const int int_c = 42;

// a pointer to a constant integer
const int* int_c_p = &int_c;

// a constant pointer to an integer
int* const int_p = &int_arr[5];


int main()
{
	return 0;
}
