#pragma once

struct RenderThread;

/**
 * Superclase de las entidades de la aplicaci�n.
 *
 * Tienen un m�todo update() para ejecutar la "l�gica" y un m�todo render()
 * para hacer el renderizado.
 */
struct Entity
{
	virtual ~Entity() {}

	/**
	 * M�todo llamado para hacer la actualizaci�n en cada tick.
	 *
	 * @return Cierto si la entidad debe seguir viva en este frame. Si se devuelve
	 * falso, se eliminar� de la lista de entidades en este mismo frame y ni siquiera
	 * se llamar� al m�todo render().
	 */
	virtual bool update() { return true; };

	// Render.
	virtual void render(RenderThread& rThread) const = 0;
};