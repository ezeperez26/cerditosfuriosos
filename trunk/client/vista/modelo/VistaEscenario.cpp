// Header Include.
#include "VistaEscenario.h"

// Forward Includes.
#include "VistaCuerpo.h"

//Project Includes.
#include "VistaCerdito.h"
#include "VistaPajaroRojo.h"
#include "ConstantesVistaModelo.h"

VistaEscenario::VistaEscenario(Escenario* escenario) {
	// Almaceno el escenario
	this->escenario = escenario;
	// Registro la vista del escenario en el escenario del modelo.
	this->escenario->registrarObservador(this);
	// Ajusto las dimensiones del fixed al tamaño del escenario.
	this->ancho = escenario->getAncho() * AJUSTE_ESCALA_VISTA;
	this->alto = escenario->getAlto() * AJUSTE_ESCALA_VISTA;
	this->set_size_request(ancho, alto);
	// Agrego el fondo en el fixed. TODO Implementar
}

VistaEscenario::~VistaEscenario() {
	// Libero la memoria de las vistas
	std::list<VistaCuerpo*>::iterator it;
	for(it = this->vCuerpos.begin(); it != this->vCuerpos.end(); ++it) {
		delete (*it);
	}
}

void VistaEscenario::mover(VistaCuerpo* cuerpo, int x, int y) {
	this->move(*cuerpo, x, y);
}

void VistaEscenario::eliminar(VistaCuerpo* cuerpo) {
	this->remove(*cuerpo);
}

void VistaEscenario::seAgregoCerdito(Cerdito* cerdito) {
	VistaCerdito* vCerdito = new VistaCerdito(this, cerdito);
	this->vCuerpos.push_back(vCerdito);
	show_all();
}

void VistaEscenario::seAgregoCatapulta(Catapulta* catapulta) {

}

void VistaEscenario::seAgregoMonticulo(Monticulo* monticulo) {

}

void VistaEscenario::seAgregoCajaVidrio(CajaVidrio* caja) {

}

void VistaEscenario::seAgregoCajaMadera(CajaMadera* caja) {

}

void VistaEscenario::seAgregoCajaMetal(CajaMetal* caja) {

}

void VistaEscenario::seAgregoManzana(Manzana* manzana) {

}

void VistaEscenario::seAgregoBanana(Banana* banana) {

}

void VistaEscenario::seAgregoCereza(Cereza* cereza) {

}

void VistaEscenario::seLanzoPajaroRojo(PajaroRojo* pajaro) {
	VistaPajaroRojo* vPajaro = new VistaPajaroRojo(this, pajaro);
	this->vCuerpos.push_back(vPajaro);
	show_all();
}

void VistaEscenario::seLanzoPajaroVerde(PajaroVerde* pajaro) {

}

void VistaEscenario::seLanzoPajaroAzul(PajaroAzul* pajaro) {

}

void VistaEscenario::seLanzoHuevoBlanco(HuevoBlanco* huevo) {

}

void VistaEscenario::seLanzoHuevoCodorniz(HuevoCodorniz* huevo) {

}

void VistaEscenario::seLanzoHuevoPoche(HuevoPoche* huevo) {

}

void VistaEscenario::seLanzoHuevoReloj(HuevoReloj* huevo) {

}

void VistaEscenario::monticuloDestruido() {

}

/* Metodo que será usado en el caso de que el escenario tenga un único cerdito.
 */
void VistaEscenario::cerditoMatado() {

}

/* Método que será usado en el caso multijugador, donde el escenario tiene
 * varios cerditos.
 * El parámetro es el nombre del jugador al que corresponde el cerdito matado.
 */
void VistaEscenario::cerditoMatado(std::string nombreJugador) {

}

void VistaEscenario::partidaGanada() {

}

int VistaEscenario::getAncho() const {
	return this->ancho;
}
int VistaEscenario::getAlto() const {
	return this->alto;
}
