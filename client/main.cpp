/* Aplicación del cliente
 *
 */

// Standard C++ Library Includes.
#include <iostream>

// gtkmm Library Includes.
#include <gtkmm/main.h>

// Project Includes.
#include "vista/VentanaCliente.h"
#include "vista/modelo/VistaEscenario.h"
#include "core/Client.h"
#include "Escenario.h"
#include "controlador/Juego.h"
#include "controlador/MouseListener.h"
#include "vista/modelo/ConstantesVistaModelo.h"


int maind(int argc, char *argv[]) {
	Gtk::Main kit(argc, argv);
	VentanaCliente ventana;

	// begin -- Inicializacion de escenario.
	Escenario escenario;

	Juego juego(&escenario, &ventana);
	juego.start();

	Gtk::Main::run(ventana);

	juego.finalizarJuego();
	juego.join();
	return 0;
}

int main(int argc, char **argv) {
	Client* c = new Client("127.0.0.1", 5555);
	c->conectar();
	c->ejecutar();
	c->desconectar();
	delete c;
	return 0;
}



