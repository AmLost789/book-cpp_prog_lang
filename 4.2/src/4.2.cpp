#include <string>
#include <complex>

extern char ch;
extern std::string s;
extern int count;
extern const double pi;
int error_number = -1;

extern const char* name;
extern const char* season[];

struct Date;
int day(Date* p);
double sqrt(double x) { return(x + x); }
template<class T> T abs(T a);

//typedef std::complex<short> Point;	Not sure about definition at this point.
struct User { int xx; };
enum Beer: unsigned int;
//namespace NS;							Not sure about definition at this point.

int main()
{
	;
}
