#pragma once
#include <string>

namespace Console
{
    enum class Color
    {
        BLACK,
        BLUE,
        GREEN,
        AQUA,
        RED,
        PURPLE,
        YELLOW,
        WHITE,
        GREY,

        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_AQUA,
        LIGHT_RED,
        LIGHT_PURPLE,
        LIGHT_YELLOW,
        BRIGHT_WHITE,

        Colour_Size,
    };

    using Colour = Color;

    inline std::string GetAnsiEscapeSequence(Color colour, bool isForeground)
    {
        const std::string foregroundBase = "\033[3";
        const std::string backgroundBase = "\033[4";

        std::string code;
        switch (colour)
        {
            case Color::BLACK:         code = "0"; break;
            case Color::RED:           code = "1"; break;
            case Color::GREEN:         code = "2"; break;
            case Color::YELLOW:        code = "3"; break;
            case Color::BLUE:          code = "4"; break;
            case Color::PURPLE:        code = "5"; break;
            case Color::AQUA:          code = "6"; break;
            case Color::WHITE:         code = "7"; break;
            case Color::GREY:          code = "8"; break;

            case Color::LIGHT_RED:     code = "9"; break;
            case Color::LIGHT_GREEN:   code = "10"; break;
            case Color::LIGHT_YELLOW:  code = "11"; break;
            case Color::LIGHT_BLUE:    code = "12"; break;
            case Color::LIGHT_PURPLE:  code = "13"; break;
            case Color::LIGHT_AQUA:    code = "14"; break;
            case Color::BRIGHT_WHITE:  code = "15"; break;

            default:                    code = "0"; break;
        }

        return (isForeground ? foregroundBase : backgroundBase) + code + "m";
    }
}
