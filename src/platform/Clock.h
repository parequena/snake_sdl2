#pragma once

#include <chrono>

class Clock {

public:

	/**
	* Constructor.
	*/
	Clock()
		: m_startTime(std::chrono::system_clock::time_point::min())
	{ }

	/**
	* Borra el punto inicial, dejando en "parado" al temporizador.
	*/
	inline constexpr void clear() { m_startTime = std::chrono::system_clock::time_point::min(); } // clear

    /**
	 * Devuelve cierto si se ha lanzado la medici�n de tiempo (se ha llamado previamente
	 * a start()).
	 */
	inline constexpr bool isStarted() const { return (m_startTime.time_since_epoch() != std::chrono::system_clock::duration(0)); }

	/**
	* Anota el instante de tiempo actual, como punto de inicio para la medici�n de tiempo
	* transcurrido.
	*/
	inline void start() { m_startTime = std::chrono::system_clock::now(); }

	/**
	* Devuelve el tiempo transcurrido desde la �ltima llamada a start() en microsegundos
	* o 0 si no se ha llamado nunca.
	*/
	unsigned long getMicros() const
	{
		if (isStarted())
		{
			std::chrono::system_clock::duration diff;
			diff = std::chrono::system_clock::now() - m_startTime;
			return static_cast<unsigned>((std::chrono::duration_cast<std::chrono::microseconds>(diff).count()));
		}
		return 0;
	}

private:

	std::chrono::system_clock::time_point m_startTime;

}; // class Clock