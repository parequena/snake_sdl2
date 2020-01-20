#include "src/platform/Platform.h"
#include "src/renderer/Renderer.h"
#include "src/platform/Clock.h"
#include "src/logic/Logic.h"
#include "src/logic/Color.h"
#include "src/logic/Ball.h"
#include "src/renderThread/RenderThread.h"

// Informe de FPSs
#include <iostream>

// Bucle principal de la aplicaci�n. Recibe la hebra de render a utilizar
// para pintar. Asume todo inicializado previamente.
// Devuelve el n�mero de frames/vueltas dadas por el bucle antes de terminar.
long long MainLoop(RenderThread& rThread)
{
	constexpr unsigned int numFrames = 2000;
	auto nFrame = 0;
	unsigned int pendingFrames = numFrames;
	uint32_t colorFondo = Color::BLUE.toARGB();

	// Bucle principal
	while (Platform::Tick() && --pendingFrames)
	{
		Logic::Tick();

		// Renderer::Clear(colorFondo);
		rThread.push_command(RenderCommand{0, 0, 0, 0, 0, colorFondo});
		Logic::Render(rThread);
		nFrame++;
		// Renderer::Present();
		rThread.push_command(RenderCommand{ 2 });

		while (rThread.getPending() > 3);

	} // while bucle principal

	return numFrames - (pendingFrames + 1);
}

int main()
{
	// Inicializaci�n
	Platform::Init();
	/*
	Renderer::Init(true, 768, 432);	 // En ventana
	/*/
	Renderer::Init(false);		// Pantalla completa
	/**/
	Logic::Init();

	RenderThread renderThread; // Create the renderThread.
	renderThread.start(); // Start the thread.

	Ball* ball;

	// Bola 1
	ball = new Ball(50, 50, 718, 382, Color::RED);
	ball->setPos(200, 216);
	Logic::AddEntity(ball);

	// Bola 2
	ball = new Ball(50, 50, 718, 382, Color::WHITE);
	ball->setPos(568, 216);
	ball->setSpeed(-200, 200);
	Logic::AddEntity(ball);

	Clock chrono;

	// Bucle principal
	chrono.start();
	long long totalFrames = MainLoop(renderThread);
	long long totalMicros = chrono.getMicros();

	double fps = static_cast<double>((totalFrames) * 1000000 / totalMicros);
	std::cout << totalFrames << " frames en " << totalMicros / 1000 << " ms (" << fps << " fps)\n";

	// Limpieza
	renderThread.stop(); // Stop the renderThread.
	Logic::Release();
	Renderer::Release();
	Platform::Release();

	return 0;

} // main

