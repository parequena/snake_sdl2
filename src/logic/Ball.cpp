#include "Ball.h"
#include "Logic.h"
#include "../renderer/Renderer.h"

#include <algorithm> // swap
#include "../renderThread/RenderThread.h"

Ball::Ball(int x1, int y1, int x2, int y2, Color color)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_color(color)
{
	if (m_x1 > m_x2) std::swap(m_x1, m_x2);
	if (m_y1 > m_y2) std::swap(m_y1, m_y2);

	m_x = (m_x1 + m_x2) / 2;
	m_y = (m_y1 + m_y2) / 2;

	m_medioAncho = 20 / 2;
	m_medioAlto = m_medioAncho * 6;

	m_speedX = m_speedY = 300;
}

/**
* Destructor. Quita la entidad del mundo de colisi�n.
*/
Ball::~Ball() {

}

void Ball::setPos(int x, int y)
{
	m_x = x;
	m_y = y;

	m_x = std::max(m_x, m_x1 + m_medioAncho);
	m_x = std::min(m_x, m_x2 - m_medioAncho);
	m_y = std::max(m_y, m_y1 + m_medioAlto);
	m_y = std::min(m_y, m_y2 - m_medioAlto);

}

bool Ball::update()
{
	// float deltaTime = Logic::GetDeltaTimeMicroSecs() / 1000000.0f;

	const float incrX = m_speedX * 0.01f;// deltaTime;
	const float incrY = m_speedY * 0.01f;// deltaTime;

	m_x += static_cast<int>(incrX);
	m_y += static_cast<int>(incrY);

	if (m_x < m_x1) { m_x = m_x1; m_speedX *= -1; }
	if (m_x > m_x2) { m_x = m_x2; m_speedX *= -1; }
	if (m_y < m_y1) { m_y = m_y1; m_speedY *= -1; }
	if (m_y > m_y2) { m_y = m_y2; m_speedY *= -1; }

	return true;
}

void Ball::render(RenderThread& rThread) const
{
	rThread.push_command(RenderCommand{ 3, m_x, m_y, m_medioAncho, m_medioAncho, m_color.toARGB() });
} // render
