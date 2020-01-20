#pragma once

#include "Entity.h"
#include "Color.h"

struct  RenderThread;

class Ball : public Entity
{
public:

	/**
	 * Constructor. Define el rango de movimiento y el color de la bola.
	 * La coloca en el centro y con tama�o 20x20.
	 * @param color Color del muro
	 */
	Ball(int x1, int y1, int x2, int y2, Color color);

	/**
	 * Destructor. Quita la entidad del mundo de colisi�n.
	 */
	~Ball();

	// En p�xeles por segundo
	inline void setSpeed(int speedX, int speedY) { m_speedX = speedX; m_speedY = speedY; }

	void setPos(int x, int y);

	bool update() override;
	void render(RenderThread& rThread) const override;

private:

	int m_x1{ 0 }, m_y1{ 0 }, m_x2{ 0 }, m_y2{ 0 };
	int m_x{ 0 }, m_y{ 0 };
	int m_speedX{ 0 }, m_speedY{ 0 }; // p�xeles por segundo
	int m_medioAncho{ 0 }, m_medioAlto{ 0 };
	Color m_color;

}; // class Wall