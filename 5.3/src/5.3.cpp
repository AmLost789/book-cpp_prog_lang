// Since C++11 can use typedef or equivalent 'using', where 'using' is in general easier to read.

// unsigned char
using u_char = unsigned char;

// const unsigned char
using cu_char = const unsigned char;

// pointer to integer
using int_p = int*;

// pointer to pointer to char
using char_pp = char**;

// pointer to array of char
typedef char (*char_arr_p)[3];

// array of 7 pointers to int
typedef int* int_7p[7];

// pointer to an array of 8 pointers to int
// NOTE: EASIEST TO TAKE INTERPRETATION ONE STEP AT A TIME. --------------------
//
//       *int_p_arr_p      :  A pointer
//      (*int_p_arr_p)[8]  :  A pointer to an array of 8
// int* (*int_p_arr_p)[8]  :  A pointer to an array of 8 pointers to int
typedef int* (*int_p_arr_p8)[8];

// array of 8 arrays of 7 pointers to int
// NOTE: AN ALTERNATIVE IS TO 'CHAIN' TYPEDEFS TO MAKE THEM MORE DIGESTABLE ----------------
typedef int* (int_arr8_p7[8])[7];
typedef int_7p int_arr8_p7_alternate[8];

///---definitions: for testing correct typedefs----------

u_char tmp1 = 'a';

cu_char tmp2 = 'b';

int tmp3 = 4;
int_p tmp4 = &tmp3;

char tmp5 = 'a';
char* tmp6 = &tmp5;
char_pp tmp7 = &tmp6;

char tmp8[3] = "No";
char_arr_p tmp9 = &tmp8;

int_7p tmp11 = { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 };

int* tmp12[8] = { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 };
int_p_arr_p8 tmp13 = &tmp12;

int_arr8_p7 tmp14 = { { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
					  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 }, };

int_arr8_p7_alternate tmp15 = { { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 },
		  { &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3, &tmp3 }, };

int main()
{
	return 0;
}
