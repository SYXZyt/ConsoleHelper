#pragma once
#include <Console/RGBColor.h>
#include <Console/Color.h>

namespace Console
{
	struct CInfo
	{
		bool isRGB;
		bool isBack;

		RGBColor rgb;
		Color dos;

		CInfo(RGBColor rgb, bool isBack = false)
		{
			this->rgb = rgb;
			this->isBack = isBack;

			isRGB = true;
		}

		CInfo(Color dos, bool isBack = false)
		{
			this->dos = dos;
			this->isBack = isBack;

			isRGB = false;
		}
	};
}