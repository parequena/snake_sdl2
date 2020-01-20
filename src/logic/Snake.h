#pragma once

#include "Entity.h"
#include "Color.h"
#include <vector>

constexpr uint8_t kSnakeW{ 10 }, kSnakeH{ 10 };
using Point = std::pair<int, int>;


struct Snake : public Entity
{
	// Ctor.
	explicit Snake(int x, int y, int size, Color color);

	// Dtor.
	~Snake() = default;

	// Update.
	bool update() override;

	// Render.
	void render(RenderThread& rThread) const override;

private:

	const uint8_t m_w{ kSnakeW }, m_h{ kSnakeH };

	int m_x{ 0 },
		m_y{ 0 },
		m_size{ 1 };

	// Color
	Color m_color;

	std::vector<Point> m_snake;
}; // struct Snake