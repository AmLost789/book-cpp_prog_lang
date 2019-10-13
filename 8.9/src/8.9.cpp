//--------------------------------------------------------------------------------------
// NOTE: COPIED FROM PROJECT 8.3 AS A STARTING POINT.
//--------------------------------------------------------------------------------------

// The desk calulator

// reads from std::cin
// uses namespaces, but no exceptions

// pp 163-171, sec 8.2, Namespaces


// uses += rather than push_back() for string
// to work around standard library bug

// No guarantees offered. Constructive comments to bs@research.att.com

/*
	program:
		END			   // END is end-of-input
		expr_list END

	expr_list:
		expression PRINT	   // PRINT is ';'
		expression PRINT expr_list

	expression:
		expression + term
		expression - term
		term

	term:
		term / primary
		term * primary
		primary

	primary:
		NUMBER
		NAME
		NAME = expression
		- primary
		( expression )
*/

#include <iostream>
#include <map>
#include <string>
#include <cctype>

// note: no "using namespace std;"

namespace Error {

	int no_of_errors;

	struct Syntax_error
	{
		Syntax_error()
		{
			std::cerr << "Syntax error.\n";
			no_of_errors++;
		}

		Syntax_error(std::string str)
		{
			std::cerr << "Syntax error: " << str << "\n";
			no_of_errors++;
		}
	};

	struct Zero_divide
	{
		Zero_divide()
		{
			std::cerr << "Divide by zero error.\n";
			no_of_errors++;
		}

		Zero_divide(std::string str)
		{
			std::cerr << "Divide by zero error: " << str << "\n";
			no_of_errors++;
		}
	};
}

namespace Lexer {

	enum Token_value {
		NAME,	NUMBER,		END,
		PLUS='+',	MINUS='-',	MUL='*',	DIV='/',
		PRINT=';',	ASSIGN='=',	LP='(',		RP=')'
	};

	Token_value curr_tok;
	double number_value;
	std::string string_value;

	Token_value get_token();
}


Lexer::Token_value Lexer::get_token()
{
	char ch = 0;
	std::cin>>ch;

	switch (ch) {
	case 0:
		return END;
	case ';':
		return curr_tok=PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok=Token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		std::cin.putback(ch);
		std::cin >> number_value;
		return curr_tok=NUMBER;
	default:			// NAME, NAME =, or error
		if (isalpha(ch)) {	// warning isalpha is a macro
					// in some implementations
			std::cin.putback(ch);
			std::cin>>string_value;
			return curr_tok=NAME;
		}
		throw Error::Syntax_error("bad token");
	}
}

std::map<std::string,double> table;	// global; see sec9.???

namespace Parser {
	double prim(bool get);		// handle primaries
	double term(bool get);		// multiply and divide
	double expr(bool get);		// add and subtract

	using Lexer::get_token;		// commonly used names
	using Lexer::curr_tok;
	using Error::Syntax_error;
	using Error::Zero_divide;
}

double Parser::prim(bool get)		// handle primaries
{
	if (get) get_token();

	switch (curr_tok) {
	case Lexer::NUMBER:	// floating point constant
		get_token();
		return Lexer::number_value;
	case Lexer::NAME:
	{	double& v = table[Lexer::string_value];
  		if (get_token() == Lexer::ASSIGN) v = expr(1);
  		return v;
	}
	case Lexer::MINUS:		// unary minus
		return -prim(1);
	case Lexer::LP:
	{	double e = expr(1);
		if (curr_tok != Lexer::RP) throw Error::Syntax_error(") expected");
		get_token();			  // eat ')'
		return e;
	}
	case Lexer::END:
		return 1;
	default:
		throw Error::Syntax_error("primary expected");
	}
}

double Parser::term(bool get)		// multiply and divide
{
	double left = prim(get);

	for (;;)
	switch (curr_tok) {
	case Lexer::MUL:
		left *= prim(true);
		break;
	case Lexer::DIV:
		if (double d = prim(true)) {
		left /= d;
			break;
		}
		throw Error::Zero_divide();
	default:
		return left;
	}
}

double Parser::expr(bool get)		// add and subtract
{
	double left = term(get);

	for(;;)			// ``forever''
	switch (curr_tok) {
	case Lexer::PLUS:
		left += term(true);
		break;
	case Lexer::MINUS:
		left -= term(true);
		break;
	default:
		return left;
		}
}

namespace Driver {
	void skip();
}

void Driver::skip()
{
	while (std::cin) {	// discard characters until newline or semicolon
		char ch;
		std::cin >> ch;
		switch (ch) {
		case '\n':
		case ';':
			return;
		}
	}
}

int main(int argc, char* argv[])
{
	// insert pre-defined names:
	table["pi"] = 3.1415926535897932385;
	table["e"]  = 2.7182818284590452354;

	while (std::cin) {
		try
		{
			Lexer::get_token();
			if (Lexer::curr_tok == Lexer::END) break;
			if (Lexer::curr_tok == Lexer::PRINT) continue;
			std::cout << Parser::expr(false) << '\n';
		}
		catch (Error::Syntax_error& e)
		{
			Driver::skip();
		}
		catch (Error::Zero_divide& e)
		{
			Driver::skip();
		}
	}

	return Error::no_of_errors;
}
