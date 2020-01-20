#include "Logic.h"
#include "Entity.h"
#include "../renderThread/RenderThread.h"

std::vector<Entity*> Logic::m_entities;
uint64_t Logic::m_time = -1;
uint64_t Logic::m_deltaTime = 0;
Clock Logic::m_crono;


bool Logic::Init()
{
	m_crono.start();
	return true;
}

void Logic::Release()
{
	DestroyEntities();
}

void Logic::Tick()
{
	const auto now = m_crono.getMicros();
	if (m_time != std::numeric_limits<uint64_t>::max()) m_deltaTime = now - m_time;
	m_time = now;

	// Actualizamos las entidades y borramos las que nos pidan ser eliminadas.
	// B�sicamente queremos hacer un:
	//
	//	for (auto entity : entities)
	//		entity->update();
	//
	// pero Si entity->update() devuelve falso hay que borrarlo del vector entities.
	// Hago las dos cosas a la vez, desplazando hacia atr�s los elementos.

	auto r = m_entities.begin();
	auto w = m_entities.begin();
	for (; r < m_entities.end(); ++r)
	{
		if ((*r)->update())
		{
			*w = *r;
			++w;
		}
		else {
			// Esta entidad va al cubo.
			delete *r;
		}
	} // for recorriendo las entidades

	  // Borramos las entradas que han quedado al final.
	m_entities.erase(w, m_entities.end());

}

void Logic::Render(RenderThread& rThread)
{
	for (const auto& entity : m_entities)
		entity->render(rThread);
}

void Logic::DestroyEntities()
{
	for (auto e : m_entities)
		delete e;
	m_entities.clear();
}

void Logic::AddEntity(Entity *e)
{
	m_entities.emplace_back(e);
}
