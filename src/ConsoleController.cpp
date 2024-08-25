#include <Console/ConsoleController.h>
#include <iostream>

void Console::ConsoleController::SetForeColor(Color dosColour)
{
	printf(GetAnsiEscapeSequence(dosColour, true).c_str());
}

void Console::ConsoleController::SetBackColor(Color dosColour)
{
	printf(GetAnsiEscapeSequence(dosColour, false).c_str());
}

void Console::ConsoleController::SetForeColor(RGBColor rgbColour)
{
	printf(GetAnsiEscapeSequence(rgbColour, true).c_str());
}

void Console::ConsoleController::SetBackColor(RGBColor rgbColour)
{
	printf(GetAnsiEscapeSequence(rgbColour, false).c_str());
}