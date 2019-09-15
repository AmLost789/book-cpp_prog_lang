#include <iostream>

void f(char c)
{
	std::cout << "f:  " << static_cast<void *>(&c) << "\n";
}

void g(char& c_ref)
{
	std::cout << "g:  " << static_cast<void *>(&c_ref) << "\n";
}

void h(const char& c_const_ref)
{
	std::cout << "h:  " << static_cast<const void *>(&c_const_ref) << "\n";
}

// This article gives a good explanation.
// - see: https://stackoverflow.com/questions/18565167/non-const-lvalue-references
//
// Note; need to cast address of char since value is "char*" and cout is trying to print as a string.
// - see: https://stackoverflow.com/questions/4860788/why-is-address-of-char-data-not-displayed

int main()
{
	char c = 'b';
	unsigned char uc = 'c';
	signed char sc = 'd';

	std::cout << "c:  " << static_cast<void *>(&c)  << "\n";
	std::cout << "uc: " << static_cast<void *>(&uc) << "\n";
	std::cout << "sc: " << static_cast<void *>(&sc) << "\n";
	std::cout << "\n";

	f('a');
//	g('a');		Compiler error: 'Temporary' made for converting const char ('a') to char, and can't use for reference (char&) since the reference cannot refer to a temporary.
	h('a');
	std::cout << "\n";

	f(49);
//	g(49);		Compiler error: 'Temporary' made for converting int to char, and can't use for reference (char&) since the reference cannot refer to a temporary.
	h(49);
	std::cout << "\n";

	f(3300);	// Compiler warning: Implicit conversion of int to char is losing precision.
//	g(3300);	Compiler error: 'Temporary' made for converting int to char, and can't use for reference (char&) since the reference cannot refer to a temporary.
	h(3300);	// Compiler warning: Implicit conversion of int to char is losing precision.
	std::cout << "\n";

	f(c);
	g(c);		// Original variable 'c' using within function in this case without making of temporary variable.
	h(c);		// Original variable 'c' using within function in this case without making of temporary variable.
	std::cout << "\n";

	f(uc);
//	g(uc);		Compiler error: 'Temporary' made for converting uknsigned char to char, and can't use for reference (char&) since the reference cannot refer to a temporary.
	h(uc);
	std::cout << "\n";

	f(sc);
//	g(sc);		Compiler error: 'Temporary' made for converting signed char to char, and can't use for reference (char&) since the reference cannot refer to a temporary.
	h(sc);

	// Original variable 'c' only using within g() and h() functions (where temporary is not made).  All other function calls result
	// in use of temporary variable.

	return 0;
}
