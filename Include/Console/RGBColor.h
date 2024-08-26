#pragma once
#include <Console/Types.h>
#include <sstream>
#include <string>

namespace Console
{
	struct RGBColor final
	{
		u8 r, g, b;

		RGBColor() = default;
		RGBColor(int r, int g, int b) : r(r), g(g), b(b) {}
		RGBColor(u8 r, u8 g, u8 b) : r(r), g(g), b(b) {}
	};

	using RGBColour = RGBColor;

	inline std::string GetAnsiEscapeSequence(const RGBColor& colour, bool isForeground)
	{
		const std::string foregroundBase = "\033[38;2;";
		const std::string backgroundBase = "\033[48;2;";
		std::stringstream ss;

		if (isForeground)
			ss << foregroundBase << (int)(colour.r) << ";" << (int)(colour.g) << ";" << (int)(colour.b) << "m";
		else
			ss << backgroundBase << (int)(colour.r) << ";" << (int)(colour.g) << ";" << (int)(colour.b) << "m";

		return ss.str();
	}
}