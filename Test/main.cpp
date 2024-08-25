#include <Console/ConsoleController.h>

#include <iostream>

int main(int, char**)
{
	Console::ConsoleController console{};
	console << "He" << Console::Colour::RED << Console::CInfo(Console::RGBColor(155, 140, 2), true) << "llo" << Console::Colour::WHITE << "\n";
}