#pragma once

#include <cstdint> // uint32_t (color) C++11

struct SDL_Window;
struct SDL_Renderer;

/**
 * M�dulo Renderer usando SDL.
 */
class Renderer
{
public:

	/**
	 * Constante que en realidad act�a como constante de precompilador :-) para
	 * decidir si se usar� o no sincronizaci�n vertical en los flips.
	 */
	static constexpr bool FLIPT_AT_VSYNC = false;

	/**
	 * Inicializa el renderer con SDL. Asume que SDL est� ya inicializado.
	 */
	static bool Init(bool windowed = false, int preferredSizeX = 800, int preferredSizeY = 600);
	static void Release();

	static void Clear(uint32_t argb);
	static void PutPixel(int x, int y, uint32_t argb);

	/**
	 * Muestra el siguiente frame, haciendo visible el back buffer constru�do.
	 * Dependiendo de si la constante FLIPT_AT_VSYNC es o no cierta, el cambio
	 * se sincronizar� con el retrazado vertical, en cuyo caso la llamada ser� bloqueante.
	 */
	static void Present();

	static int getWidthRes() { return sizeX; }
	static int getHeightRes() { return sizeY; }

private:

	static void setColor(uint32_t argb);
	static SDL_Window *mWindow;
	static SDL_Renderer *mSDLRenderer;
	static int sizeX, sizeY;

}; // class RendererPC