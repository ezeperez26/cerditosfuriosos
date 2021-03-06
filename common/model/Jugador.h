#ifndef JUGADOR_H_
#define JUGADOR_H_

//Project Includes.
#include "Cerdito.h"
#include "Puntaje.h"

/* Clase Jugador que contiene los datos necesarios para el juego
 * Cerditos Furiosos.
 */
class Jugador {
public:
	/* Constructor que recibe el cerdito asociado
	 */
	explicit Jugador(Cerdito* cerdito, unsigned int id);

	virtual ~Jugador();

	/* Suma los puntos especificados.
	 * @param puntos a incrementar en el jugador.
	 */
	void sumarPuntos(int puntos);

	bool perdio();

	Cerdito* getCerdito();

	unsigned int getId() const;

	bool estaConectado();
	void setConectado(bool conectado);

private:
	unsigned int id;

	// Cerdito asociado al jugador
	Cerdito* cerdito;

	// Puntaje del jugador
	Puntaje puntaje;

	// flag para indicar si hay un cliente manejandolo
	bool conectado;
};

#endif /* JUGADOR_H_ */
