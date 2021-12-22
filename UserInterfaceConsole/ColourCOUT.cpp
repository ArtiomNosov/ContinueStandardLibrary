#include "ColourCOUT.h"

struct setcolour
{
	colour _c;
	HANDLE _console_handle;
	setcolour(colour c, HANDLE console_handle)
		: _c(c), _console_handle(0)
	{
		_console_handle = console_handle;
	}
};
std::basic_ostream<char>& operator<<(std::basic_ostream<char>& s, const setcolour& ref)
{
	SetConsoleTextAttribute(ref._console_handle, ref._c);
	return s;
}
void printNumberWithColor(int n, colour c)
{
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (c == colour(0))
	{
		c = WHITE;
	}
	std::cout << setcolour(c, chandle) << n;
	if (c != WHITE)
	{
		std::cout << setcolour(WHITE, chandle);
	}
}
template<class T>
void printWithColor(T data, colour c)
{
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (c == colour(0))
	{
		c = WHITE;
	}
	std::cout << setcolour(c, chandle) << data;
	if (c != WHITE)
	{
		std::cout << setcolour(WHITE, chandle);
	}
}