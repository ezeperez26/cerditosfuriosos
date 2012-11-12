#include "CreadorMundo.h"

CreadorMundo::CreadorMundo(std::map<std::string, std::string> nombreMundos) {
	this->nombreMundos = nombreMundos;
	// Widgets
	Gtk::Label* etiquetaNombre = manage(new Gtk::Label(
									"Seleccione un nombre para el mundo: "));
	nombre = new Gtk::Entry();
	Gtk::Label* etiquetaCantidadJugadores = manage(new Gtk::Label(
									"Seleccione su cantidad de jugadores: "));
	ajuste = new Gtk::Adjustment(1.0, 1.0, 5.0);
	cantidadJugadores = new Gtk::SpinButton(*ajuste);
	cantidadJugadores->set_editable(false);
	// Contenedores
	Gtk::HBox* cajaHorizontalUno = manage(new Gtk::HBox(false, 20));
	Gtk::HBox* cajaHorizontalDos = manage(new Gtk::HBox(false, 20));
	Gtk::VBox* cajaVertical = manage(new Gtk::VBox(false, 30));
	cajaHorizontalUno->pack_start(*etiquetaNombre);
	cajaHorizontalUno->pack_start(*nombre);
	cajaHorizontalDos->pack_start(*etiquetaCantidadJugadores);
	cajaHorizontalDos->pack_start(*cantidadJugadores);	
	cajaVertical->pack_start(*cajaHorizontalUno);
	cajaVertical->pack_start(*cajaHorizontalDos);
	add(*cajaVertical);
}

bool CreadorMundo::nombreSeleccionadoValido() {
	std::string nombreSeleccionado = nombre->get_text();
	if (nombreSeleccionado.size() == 0)
		return false;
	std::map<std::string, std::string>::iterator iterador = nombreMundos.begin();
	while (iterador != nombreMundos.end()) {
		if (nombreSeleccionado.compare(iterador->second) == 0)
			return false;
		++iterador;
	}
	return true;
}

CreadorMundo::~CreadorMundo() {
	delete nombre;
	delete ajuste;
	delete cantidadJugadores;
}
