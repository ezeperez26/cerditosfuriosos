#include "Nivel.h"
#include <exception>
#include "../parser/XMLTypes.h"

Nivel::Nivel() { }

Nivel::~Nivel() { }

void Nivel::cargarXML(std::string path) {
	XMLDocument doc;
	bool cargoArchivo = doc.LoadFile(path);
	// Si no se cargo, lanzo error.
	if (cargoArchivo == false) {
		std::cout << "\tError al abrir el archivo XML." << std::endl;
	} else {
		// Obtengo el elemento raiz, que debe ser <Nivel>, pero no valido.
		const XMLNode* root = doc.RootElement();
		// Obtengo el atributo de duracion
		int duracion = 0;
		const char* sD = root->Attribute("duracion", &duracion);
		if ((sD != 0) && (duracion > 0)) {
			this->escenario->setDuracionJuego(duracion);
		}
		// Obtengo el primer elemento hijo que debe ser <Escenario>
		const XMLNode* nodo = root->FirstChildElement("Escenario");
		// Si el nodo no es nulo, cargo el escenario a partir del mismo.
		if (nodo != 0) {
			this->escenario->hydrate(nodo);
		} else {
			throw std::exception();
		}
		// Obtengo  el nodo de linea de entradas de pájaros
		nodo = root->FirstChildElement("LineaEntradaDerecha");
		this->cargarSimulador(nodo);
	}
}

Escenario* Nivel::getEscenario() {
	return this->escenario;
}

float Nivel::getAlto() const {
	return this->escenario->getAlto();
}

Punto2D Nivel::getPosicionCatapulta(unsigned int idJugador) {
	return escenario->getPosicionCatapulta(idJugador);
}
