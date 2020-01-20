#pragma once

/**
	Funciones basicas de la plataforma.

	Todas son est�ticas; tambi�n podr�a haber sido un singleton.
*/
struct Platform
{
	static bool Init();
	static void Release();
	static bool Tick();
};