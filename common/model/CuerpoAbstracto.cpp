// Header Include.
#include "CuerpoAbstracto.h"

#include <cstdio>  // TODO PROVISORIO, BORRAR

CuerpoAbstracto::CuerpoAbstracto() {
	// TODO Auto-generated constructor stub

}

CuerpoAbstracto::~CuerpoAbstracto() {
	// TODO Auto-generated destructor stub
}

bool CuerpoAbstracto::estaVivo() const {
	if (this->vida <= 0)
		return false;
	return true;
}

void CuerpoAbstracto::daniar(float danio) {
	this->vida -= danio;
}

void CuerpoAbstracto::matar() {
	this->vida = 0;
}

void CuerpoAbstracto::printPosition() const {
	b2Vec2 position = this->cuerpo->GetPosition();
	printf("Cuerpo: x=%4.2f y=%4.2f  ", position.x, position.y);
}