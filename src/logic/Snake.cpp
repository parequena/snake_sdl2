#include "Snake.h"
#include "Logic.h"

Snake::Snake(int x, int y, int size, Color color)
	: m_x{ x }
	, m_y{ y }
	, m_size{ size }
	, m_color{ color }
{
	for (auto i = 0; i < size; ++i)
	{
		m_snake.emplace_back(std::make_pair(x, y));
		x += m_w;
		y += m_h;
	}
}

// Update.
bool Snake::update()
{
	// Head
	// auto head = m_snake.front();
	m_snake.pop_back();


	// float deltaTime = Logic::GetDeltaTimeMicroSecs() / 1000000.0f;

	/*const float incrX = m_speedX * 0.01f;// deltaTime;
	const float incrY = m_speedY * 0.01f;// deltaTime;

	m_x += static_cast<int>(incrX);
	m_y += static_cast<int>(incrY);

	if (m_x < m_x1) { m_x = m_x1; m_speedX *= -1; }
	if (m_x > m_x2) { m_x = m_x2; m_speedX *= -1; }
	if (m_y < m_y1) { m_y = m_y1; m_speedY *= -1; }
	if (m_y > m_y2) { m_y = m_y2; m_speedY *= -1; }

	return true;*/

	return false;
}

// Render.
void Snake::render(RenderThread& rThread) const
{
}