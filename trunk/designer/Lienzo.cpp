#include "Lienzo.h"

Lienzo::Lienzo(int ancho,
				int alto,
				int cantidadJugadores,
				string rutaFondo,
				InformableSeleccion* informable) {
	this->cantidadJugadores = cantidadJugadores;
	this->ancho = ancho;
	this->alto = alto;
	this->informable = informable;
	agregarFondo(rutaFondo);
	set_size_request(ancho, alto);
	listaObjetivos.push_back(Gtk::TargetEntry("POSICIONABLE"));
	drag_dest_set(listaObjetivos);
	this->signal_drag_data_received().connect(sigc::mem_fun(*this,
		&Lienzo::recibirInformacion));
}

Lienzo::~Lienzo() {}

void Lienzo::eliminarImagen(string id) {
	eliminarPosicionable(id);
	list<ImagenCerdo*>::iterator iterador = cerdos.begin();
	while (iterador != cerdos.end()) {
		if ((*iterador)->getId().compare(id) == 0) {
			remove(*(*iterador));
			cerdos.erase(iterador);
			return;
		}
		++iterador;
	}
	list<ImagenHuevos*>::iterator iteradorDos = huevos.begin();
	while (iteradorDos != huevos.end()) {
		if ((*iteradorDos)->getId().compare(id) == 0) {
			remove(*(*iteradorDos));
			huevos.erase(iteradorDos);
			return;
		}
		++iteradorDos;
	}
	list<ImagenCajaMadera*>::iterator iteradorTres = cajasMadera.begin();
	while (iteradorTres != cajasMadera.end()) {
		if ((*iteradorTres)->getId().compare(id) == 0) {
			remove(*(*iteradorTres));
			cajasMadera.erase(iteradorTres);
			return;
		}
		++iteradorTres;
	}
	list<ImagenCajaMetal*>::iterator iteradorCuatro = cajasMetal.begin();
	while (iteradorCuatro != cajasMetal.end()) {
		if ((*iteradorCuatro)->getId().compare(id) == 0) {
			remove(*(*iteradorCuatro));
			cajasMetal.erase(iteradorCuatro);
			return;
		}
		++iteradorCuatro;
	}
	list<ImagenCajaVidrio*>::iterator iteradorCinco = cajasVidrio.begin();
	while (iteradorCinco != cajasVidrio.end()) {
		if ((*iteradorCinco)->getId().compare(id) == 0) {
			remove(*(*iteradorCinco));
			cajasVidrio.erase(iteradorCinco);
			return;
		}
		++iteradorCinco;
	}
	list<ImagenBanana*>::iterator iteradorSeis = bananas.begin();
	while (iteradorSeis != bananas.end()) {
		if ((*iteradorSeis)->getId().compare(id) == 0) {
			remove(*(*iteradorSeis));
			bananas.erase(iteradorSeis);
			return;
		}
		++iteradorSeis;
	}
	list<ImagenCereza*>::iterator iteradorSiete = cerezas.begin();
	while (iteradorSiete != cerezas.end()) {
		if ((*iteradorSiete)->getId().compare(id) == 0) {
			remove(*(*iteradorSiete));
			cerezas.erase(iteradorSiete);
			return;
		}
		++iteradorSiete;
	}
	list<ImagenManzana*>::iterator iteradorOcho = manzanas.begin();
	while (iteradorOcho != manzanas.end()) {
		if ((*iteradorOcho)->getId().compare(id) == 0) {
			remove(*(*iteradorOcho));
			manzanas.erase(iteradorOcho);
			return;
		}
		++iteradorOcho;
	}
	list<ImagenCatapulta*>::iterator iteradorNueve = catapultas.begin();
	while (iteradorNueve != catapultas.end()) {
		if ((*iteradorNueve)->getId().compare(id) == 0) {
			remove(*(*iteradorNueve));
			catapultas.erase(iteradorNueve);
			return;
		}
		++iteradorNueve;
	}
}

void Lienzo::recibirInformacion(
								const Glib::RefPtr<Gdk::DragContext>& context,
								int x,
								int y,
								const Gtk::SelectionData& selection_data,
								guint info,
								guint time) {
	x = x+2;
	y = y+2;
	string recepcion = selection_data.get_data_as_string();
	if (recepcion.compare("CERDO") == 0)
		agregarCerdo(x, y);
	else {
		if (recepcion.compare("CAJA_MADERA") == 0)
			agregarCajaMadera(x, y);
		else {
			if (recepcion.compare("CAJA_METAL") == 0)
				agregarCajaMetal(x, y);
			else {
				if (recepcion.compare("CAJA_VIDRIO") == 0)
					agregarCajaVidrio(x, y);
				else {
					if (recepcion.compare("BANANA") == 0)
						agregarBanana(x, y);
					else {
						if (recepcion.compare("CEREZA") == 0)
							agregarCereza(x, y);
						else {
							if (recepcion.compare("MANZANA") == 0)
								agregarManzana(x, y);
							else {
								if (recepcion.compare("HUEVOS") == 0)
									agregarHuevos(x, y);
								else {
									if (recepcion.compare("CATAPULTA") == 0)
										agregarCatapulta(x, y);
									else {
										moverObjeto(recepcion, x, y);
										return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void Lienzo::agregarFondo(string rutaImagen) {
	Glib::RefPtr<Gdk::Pixbuf> buffer;
	buffer = Gdk::Pixbuf::create_from_file(rutaImagen);
	buffer = buffer->scale_simple(ancho, alto, Gdk::INTERP_BILINEAR);
	imagenFondo = manage(new Gtk::Image(buffer));
	put(*imagenFondo, 0, 0);
}

void Lienzo::eliminarPosicionable(string id) {
	list<ImagenPosicionable*>::iterator iterador = posicionables.begin();
	while (iterador != posicionables.end()) {
		if ((*iterador)->getId().compare(id) == 0) {
			posicionables.erase(iterador);
			break;
		}
		++iterador;
	}
}

void Lienzo::copiarFondo(int x, int y, ImagenPosicionable* imagen) {
	Glib::RefPtr<Gdk::Pixbuf> buffer = imagenFondo->get_pixbuf();
	Glib::RefPtr<Gdk::Pixbuf> fondo = Gdk::Pixbuf::create_subpixbuf(buffer, x, y, imagen->ancho, imagen->alto);
	imagen->setFondo(fondo);
}

void Lienzo::agregarCerdo(int x, int y) {
	if (cerdos.size() < cantidadJugadores) {
		ImagenCerdo* imagen = new ImagenCerdo(x, y);
		if (!coincidenciaOcupacional(x, y, imagen)) {
			if (dentroDeEscenario(x, y, imagen)) {
				copiarFondo(x, y, imagen);
				manage(imagen);
				cerdos.push_front(imagen);
				posicionables.push_front(imagen);
				put(*imagen, x, y);
				show_all();
				return;
			} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
		} else
			informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
		delete imagen;
	} else
		informable->mostrarDialogo("Ya ha agregado a todos los jugadores del nivel");
}

void Lienzo::agregarHuevos(int x, int y) {
	if (huevos.size() < cantidadJugadores) {
		ImagenHuevos* imagen = new ImagenHuevos(x, y);
		if (!coincidenciaOcupacional(x, y, imagen)) {
			if (dentroDeEscenario(x, y, imagen)) {
				copiarFondo(x, y, imagen);
				manage(imagen);
				huevos.push_front(imagen);
				posicionables.push_front(imagen);
				put(*imagen, x, y);
				show_all();
				return;
			} else
				informable->mostrarDialogo("Fuera de los límites del escenario");
		} else
			informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
		delete imagen;
	} else
		informable->mostrarDialogo("Ya ha agregado un montículo por cada jugador del nivel");
}

void Lienzo::agregarCatapulta(int x, int y) {
	if (catapultas.size() < cantidadJugadores) {
		ImagenCatapulta* imagen = new ImagenCatapulta(x, y);
		if (!coincidenciaOcupacional(x, y, imagen)) {
			if (dentroDeEscenario(x, y, imagen)) {
				copiarFondo(x, y, imagen);
				manage(imagen);
				catapultas.push_front(imagen);
				posicionables.push_front(imagen);
				put(*imagen, x, y);
				show_all();
				return;
			} else
				informable->mostrarDialogo("Fuera de los límites del escenario");
		} else
			informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
		delete imagen;
	} else
		informable->mostrarDialogo("Ya ha agregado una catapulta por cada jugador del nivel");
}

void Lienzo::agregarCajaMadera(int x, int y) {
	ImagenCajaMadera* imagen = new ImagenCajaMadera(x, y);
	if (!coincidenciaOcupacional(x, y, imagen)) {
		if (dentroDeEscenario(x, y, imagen)) {
			copiarFondo(x, y, imagen);
			manage(imagen);
			cajasMadera.push_front(imagen);
			posicionables.push_front(imagen);
			put(*imagen, x, y);
			show_all();
			return;
		} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
	} else
		informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
	delete imagen;
}

void Lienzo::agregarCajaMetal(int x, int y) {
	ImagenCajaMetal* imagen = new ImagenCajaMetal(x, y);
	if (!coincidenciaOcupacional(x, y, imagen)) {
		if (dentroDeEscenario(x, y, imagen)) {
			copiarFondo(x, y, imagen);
			manage(imagen);
			cajasMetal.push_front(imagen);
			posicionables.push_front(imagen);
			put(*imagen, x, y);
			show_all();
			return;
		} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
	} else
		informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
	delete imagen;
}

void Lienzo::agregarCajaVidrio(int x, int y) {
	ImagenCajaVidrio* imagen = new ImagenCajaVidrio(x, y);
	if (!coincidenciaOcupacional(x, y, imagen)) {
		if (dentroDeEscenario(x, y, imagen)) {
			copiarFondo(x, y, imagen);
			manage(imagen);
			cajasVidrio.push_front(imagen);
			posicionables.push_front(imagen);
			put(*imagen, x, y);
			show_all();
			return;
		} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
	} else
		informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
	delete imagen;
}

void Lienzo::agregarBanana(int x, int y) {
	ImagenBanana* imagen = new ImagenBanana(x, y);
	if (!coincidenciaOcupacional(x, y, imagen)) {
		if (dentroDeEscenario(x, y, imagen)) {
			copiarFondo(x, y, imagen);
			manage(imagen);
			bananas.push_front(imagen);
			posicionables.push_front(imagen);
			put(*imagen, x, y);
			show_all();
			return;
		} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
	} else
		informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
	delete imagen;
}

void Lienzo::agregarCereza(int x, int y) {
	ImagenCereza* imagen = new ImagenCereza(x, y);
	if (!coincidenciaOcupacional(x, y, imagen)) {
		if (dentroDeEscenario(x, y, imagen)) {
			copiarFondo(x, y, imagen);
			manage(imagen);
			cerezas.push_front(imagen);
			posicionables.push_front(imagen);
			put(*imagen, x, y);
			show_all();
			return;
		} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
	} else
		informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
	delete imagen;
}

void Lienzo::agregarManzana(int x, int y) {
	ImagenManzana* imagen = new ImagenManzana(x, y);
	if (!coincidenciaOcupacional(x, y, imagen)) {
		if (dentroDeEscenario(x, y, imagen)) {
			copiarFondo(x, y, imagen);
			manage(imagen);
			manzanas.push_front(imagen);
			posicionables.push_front(imagen);
			put(*imagen, x, y);
			show_all();
			return;
		} else
			informable->mostrarDialogo("Fuera de los límites del escenario");
	} else
		informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
	delete imagen;
}

void Lienzo::moverObjeto(string id, int x, int y) {
	list<ImagenPosicionable*>::iterator iterador = posicionables.begin();
	while (iterador != posicionables.end()) {
		if ((*iterador)->getId().compare(id) == 0) {
			if (!coincidenciaOcupacional(x, y, (*iterador))) {
				if (dentroDeEscenario(x, y, (*iterador))) {
					(*iterador)->setX(x);
					(*iterador)->setY(y);
					copiarFondo(x, y, (*iterador));
					move(*(*iterador), x, y);
				} else
					informable->mostrarDialogo("Fuera de los límites del escenario");
			} else
				informable->mostrarDialogo("Coincide ocupacionalmente con otro objeto");
			return;
		}
		++iterador;
	}
}

bool Lienzo::coincidenciaOcupacional(int x, int y, ImagenPosicionable* imagen) {
	bool condicion;
	list<ImagenPosicionable*>::iterator iterador = posicionables.begin();
	while (iterador != posicionables.end()) {
		if (imagen != *iterador) {
			if (x <= ((*iterador)->getX()+(*iterador)->ancho-1)&&
				(x+imagen->ancho-1) >= ((*iterador)->getX()))
				condicion = (y <= ((*iterador)->getY()+(*iterador)->alto-1)&&
						(y+imagen->alto-1) >= ((*iterador)->getY()));
			if (condicion)
				return true;
		}
		++iterador;
	}
	return false;
}

bool Lienzo::dentroDeEscenario(int x, int y, ImagenPosicionable* imagen) {
	int ancho, alto;
	get_size_request(ancho, alto);
	if (x+imagen->ancho < ancho)
		return (y+imagen->alto < alto);
	return false;
}

bool Lienzo::cantidadJugadoresValida() {
	return (cerdos.size() == cantidadJugadores);
}

bool Lienzo::objetosJugadoresCorrectos() {
	if (cerdos.size() == catapultas.size()) {
		if (cerdos.size() == huevos.size())
			return cantidadJugadoresValida();
	}
	return false;
}

void Lienzo::cargarNivel(string rutaNivel) {
	/* 
	 * Informacion para Eze:
	 * 
	 * Este metodo se encargaria de cargar un nivel que ya se empezo a editar.
	 * 
	 * La ruta del mismo es el parametro de este metodo.
	 * 
	 * Sobrecargue los metodos para agregar a todos los objetos para que reciban
	 * los valores flotantes del modelo, los pasen a las coordenadas del
	 * diseñador y se agreguen automaticamente.
	 * 
	 * Entonces habria que ir recorriendo a todos los objetos que se extraigan
	 * del archivo e ir agregandolos mediante los metodos:
	 * 
	 * void agregarCerdo(float x, float y);
	 * void agregarHuevos(float x, float y);
	 * void agregarCatapulta(float x, float y);
	 * void agregarCajaMadera(float x, float y);
	 * void agregarCajaMetal(float x, float y);
	 * void agregarCajaVidrio(float x, float y);
	 * void agregarBanana(float x, float y);
	 * void agregarCereza(float x, float y);
	 * void agregarManzana(float x, float y);
	 */
}

void Lienzo::guardarNivel(string rutaNivel) {
	/*
	 * Informacion para Eze: Este metodo se encargaria de guardar los objetos
	 * del escenario en el archivo xml.
	 * 
	 * Para eso recibe la ruta del mismo como parametro.
	 * 
	 * Habria que recorrer las siguientes listas:
	 * 
	 * list<ImagenCajaMadera*> cajasMadera;
	 * list<ImagenCajaMetal*> cajasMetal;
	 * list<ImagenCajaVidrio*> cajasVidrio;
	 * list<ImagenCerdo*> cerdos;
	 * list<ImagenHuevos*> huevos;
	 * list<ImagenBanana*> bananas;
	 * list<ImagenCereza*> cerezas;
	 * list<ImagenManzana*> manzanas;
	 * list<ImagenCatapulta*> catapultas;
	 * 
	 * guardando cada elemento.
	 * 
	 * Para eso ya contas con saber el tipo de cada elemento (para eso estan
	 * separados en distintas listas) y todas heredan de una clase que tiene los
	 * metodos getXFlotante y getYFlotante que ya te devuelven las coordenadas
	 * que tendria el objeto dentro del modelo.
	 * 
	 * A getYFlotante le tenes que pasar como parametro el atributo de este
	 * lienzo llamado "alto", dado que como visualmente se usa un eje Y que va
	 * desde arriba hacia abajo, para convertir de la ordenada entera a la
	 * flotante del modelo hay que restarle a ese valor en un momento.
	 * 
	 * Las validaciones en cuanto a que haya un cerdo por cada jugador y a que
	 * haya una catapulta y un monticulo por cada uno ya fueron hechas antes de
	 * que se llame a este metodo.
	 * 
	 * Como convencion de a que cerdo pertenece cada catapulta y cada monticulo
	 * podes adoptar que se corresponden entre si los que se encuentren en la
	 * misma posicion de su lista correspondiente. Por ejemplo, el primer cerdo
	 * de la lista "cerdos" es el duenio de la primer catapulta de la lista
	 * "catapultas" y del primer monticulo de la lista "huevos".
	 */
}

void Lienzo::agregarCerdo(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_CERDO / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_CERDO / 2)));
	agregarCerdo(xEntero, yEntero);
}

void Lienzo::agregarHuevos(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_HUEVOS / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_HUEVOS / 2)));
	agregarHuevos(xEntero, yEntero);
}

void Lienzo::agregarCatapulta(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_CATAPULTA / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_CATAPULTA / 2)));
	agregarCatapulta(xEntero, yEntero);
}

void Lienzo::agregarCajaMadera(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_CAJA_MADERA / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_CAJA_MADERA / 2)));
	agregarCajaMadera(xEntero, yEntero);
}

void Lienzo::agregarCajaMetal(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_CAJA_METAL / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_CAJA_METAL / 2)));
	agregarCajaMetal(xEntero, yEntero);
}

void Lienzo::agregarCajaVidrio(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_CAJA_VIDRIO / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_CAJA_VIDRIO / 2)));
	agregarCajaVidrio(xEntero, yEntero);
}

void Lienzo::agregarBanana(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_BANANA / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_BANANA / 2)));
	agregarBanana(xEntero, yEntero);
}

void Lienzo::agregarCereza(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_CEREZA / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_CEREZA / 2)));
	agregarCereza(xEntero, yEntero);
}

void Lienzo::agregarManzana(float x, float y) {
	int xEntero = ((int)((x * PIXELES_SOBRE_METRO)-(ANCHO_MANZANA / 2)));
	int yEntero = ((int)((((y * PIXELES_SOBRE_METRO)-alto)*-1)-(ALTO_MANZANA / 2)));
	agregarManzana(xEntero, yEntero);
}