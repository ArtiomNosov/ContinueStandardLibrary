#pragma once
#include "pch.h"
template<class optionsTy>
void printOptions()
{
	for (int i = 0; i < int(optionsTy::Count); i++)
	{
		std::cout << i << ". " << optionsTy(i) << "\n";
	}
}
enum class MenuCodes
{
	Exit,
	LR32Y1S,
	Count,
};
// Sourse: https://coderoad.ru/899341/%D0%9F%D0%B5%D1%87%D0%B0%D1%82%D1%8C-%D1%86%D0%B2%D0%B5%D1%82%D0%BD%D0%BE%D0%B3%D0%BE-%D1%82%D0%B5%D0%BA%D1%81%D1%82%D0%B0-%D0%BD%D0%B0-%D0%BA%D0%BE%D0%BD%D1%81%D0%BE%D0%BB%D1%8C-%D0%B2-C
enum colour { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
struct setcolour;
// We could use a template here, making it more generic. Wide streams won't
// work with this version.
std::basic_ostream<char>& operator<<(std::basic_ostream<char>& s, const setcolour& ref);
void printNumberWithColor(int n, colour c);
template<class T>
void printWithColor(T data, colour c);