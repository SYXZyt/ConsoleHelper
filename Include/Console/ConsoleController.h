#pragma once
#include <Console/Color.h>
#include <Console/RGBColor.h>
#include <Console/CInfo.h>

#include <cassert>
#include <iostream>

namespace Console
{
	class ConsoleController
	{
	public:

		template <typename T>
		void Write(const T& t);

		void SetForeColor(Color dosColour);
		void SetForeColor(RGBColor rgbColour);

		void SetBackColor(Color dosColour);
		void SetBackColor(RGBColor rgbColour);

		virtual ~ConsoleController() {}
	};

	template<typename T>
	inline void ConsoleController::Write(const T& t)
	{
		std::cout << t;
	}

	template <typename T>
	ConsoleController& operator<<(ConsoleController& console, const T& t)
	{
		if constexpr (std::is_same_v<T, CInfo>)
		{
			CInfo col = (CInfo)t;
			if (col.isRGB)
			{
				if (col.isBack)
					console.SetBackColor(col.rgb);
				else
					console.SetForeColor(col.rgb);
			}
			else
			{
				if (col.isBack)
					console.SetBackColor(col.dos);
				else
					console.SetForeColor(col.dos);
			}
		}
		else if constexpr (std::is_same_v<T, Color>)
			console.SetForeColor(t);
		else if constexpr (std::is_same_v<T, RGBColor>)
			console.SetForeColor(t);
		else
			console.Write(t);

		return console;
	}
}