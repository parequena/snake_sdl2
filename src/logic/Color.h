#pragma once

#include <cstdint> // uint32_t (desde C++ 11)

struct Color
{
	float r{ 0.0f }, g{ 0.0f }, b{ 0.0f };

	uint32_t toARGB() const
	{
		uint32_t argb;
		argb = 255; // alfa
		argb <<= 8;
		argb += static_cast<int>((r * 255));
		argb <<= 8;
		argb += static_cast<int>((g * 255));
		argb <<= 8;
		argb += static_cast<int>((b * 255));
		return argb;

	} // toARGB

	static Color BLACK;
	static Color WHITE;
	static Color YELLOW;
	static Color BLUE;
	static Color RED;
	static Color GREEN;
};