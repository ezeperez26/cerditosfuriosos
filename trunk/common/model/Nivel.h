#ifndef NIVEL_H_
#define NIVEL_H_

#include "Escenario.h"
#include "Simulador.h"

class Nivel {
protected:
	Escenario* escenario;
	Simulador* simulador;
public:
	Nivel();
	virtual ~Nivel();

	void generarPajaro();
};

#endif
