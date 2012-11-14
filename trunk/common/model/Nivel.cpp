#include "Nivel.h"
#include <exception>
#include "../parser/XMLTypes.h"

Nivel::Nivel(Escenario* escenario) {
    // TODO carga del escenario y las probabilidades para el simulador
    this->escenario = escenario;
}

Nivel::~Nivel() {
	delete escenario;
}

void Nivel::cargarXML(std::string path) {
	XMLDocument doc;
	bool cargoArchivo = doc.LoadFile(path);
	// Si no se cargo, lanzo error.
	if (cargoArchivo == false) {
		std::cout << "\tError al abrir el archivo XML." << std::endl;
	} else {
		// Obtengo el elemento raiz, que debe ser <Nivel>, pero no valido.
		const XMLNode* nodo = doc.RootElement();
		// Obtengo el primer elemento hijo que debe ser <Escenario>
		nodo = nodo->FirstChildElement("Escenario");
		// Si el nodo no es nulo, cargo el escenario a partir del mismo.
		if (nodo != 0) {
			this->escenario->hydrate(nodo);
		} else {
			throw std::exception();
		}
	}
}