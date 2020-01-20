#include "Snake.h"
#include "Logic.h"

#include "../renderThread/RenderThread.h"

Snake::Snake(int x, int y, int size, Color color)
	: m_x{ x }
	, m_y{ y }
	, m_size{ size }
	, m_color{ color }
{
	m_snake.reserve(size);
	
	for (auto i = 0; i < size; ++i)
	{
		m_snake.emplace_back(std::make_pair(x, y));
		x += m_w;
		// y += m_h;
	}
}

// Update.
bool Snake::update()
{
	// Head
	// auto head = m_snake.front();
	// m_snake.pop_back();

	return true;
}

// Render.
void Snake::render(RenderThread& rThread) const
{
	for(const auto& sn : m_snake)
	{
		rThread.push_command(RenderCommand{3, sn.first, sn.second, m_w, m_h, m_color.toARGB() });
	}
}