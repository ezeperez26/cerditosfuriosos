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


int main(int argc, char *argv[]) {
	Gtk::Main kit(argc, argv);
	VentanaCliente ventana;

	// begin -- Inicializacion de escenario.
	Escenario escenario;

	// FIXME el alto y ancho del escenario deberia setearse en metros (mundo Box2D)
	// y dentro del constructor de VistaEscenario aplicarse el escalado realizando
	// la multiplicacion por AJUSTE_ESCALA_VISTA
////	int ancho = 12, alto = 6; 	// setear AJUSTE_ESCALA_VISTA = 100
////	int ancho = 14, alto = 7; 	// setear AJUSTE_ESCALA_VISTA = 80
//	int ancho = 16, alto = 8; 	// setear AJUSTE_ESCALA_VISTA = 70
////	int ancho = 18, alto = 10; 	// setear AJUSTE_ESCALA_VISTA = 60
////	int ancho = 20, alto = 12;  // setear AJUSTE_ESCALA_VISTA = 50
//	escenario.setAncho(ancho);
//	escenario.setAlto(alto);
//	escenario.setRutaImagenFondo(FONDO_BOSQUE);
//	escenario.setRutaImagenSuelo(SUELO_BOSQUE);
//
//	// end -- Inicializacion de escenario.
//
//	VistaEscenario vEscenario(&escenario);
//	ventana.agregarContenedor(&vEscenario);
//	ventana.setMouseListener(new MouseListener(&escenario));
//
//	// begin -- Hidratacion del escenario.
//	std::list<Punto2D*> p;
//	escenario.agregarSuelo(p);
//	escenario.agregarCerdito(Punto2D(1, 0.6), Punto2D(0.4, 0.6));
//	escenario.agregarMonticulo(Punto2D(5,0.6));
//	escenario.agregarCajaMadera(Punto2D(5,3));
//	escenario.agregarCajaVidrio(Punto2D(5,5));
//	escenario.agregarCajaMetal(Punto2D(3,4));
//
//	escenario.agregarBanana(Punto2D(7, 3));
//	escenario.agregarCereza(Punto2D(2, 5));
//	escenario.agregarManzana(Punto2D(5, 1.5));
//
//	escenario.habilitarSimulacion();
	// end -- Hidratacion del escenario.

	Juego juego(&escenario, &ventana);
	juego.start();

	Gtk::Main::run(ventana);

	juego.join();
	return 0;
}

int main_core(int argc, char **argv) {
	Client* c = new Client("127.0.0.1", 5555);
	c->conectar();
	c->ejecutar();
	c->desconectar();
	delete c;
	return 0;
}


