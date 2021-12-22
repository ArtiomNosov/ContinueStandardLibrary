#include "pch.h"
/*
*	UIMainCycle.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "UIMainCycle.h"
/**/
#include "UILR32Y1SCycle.h"
std::ostream& operator<<(std::ostream& os, MenuCodes Token)
{
	switch (Token)
	{
	case MenuCodes::LR32Y1S:
		os << "LR32Y1S";
		break;
	case MenuCodes::Exit:
		os << "Exit";
		break;
	}
	return os;
}
void UIMainCycle()
{
	bool isCycle = true;
	int up = 0;
	while (isCycle)
	{
		std::cout << "***Выберите лабораторную работу***\n";
		printOptions<MenuCodes>();
		std::cin >> up;
		switch (up)
		{
		case (int)MenuCodes::LR32Y1S:
			UIUILR32Y1SCycle();
			break;
		case (int)MenuCodes::Exit:
			isCycle = bool(MenuCodes::Exit);
			break;
		default:
			break;
		}
		system("cls");
	}
}
