// Header Include.
#include "VistaEscenario.h"

// Forward Includes.
#include "VistaCuerpo.h"

// Project Includes.
#include "VistaCerdito.h"
#include "VistaCatapulta.h"
#include "VistaMonticulo.h"
#include "VistaCajaMadera.h"
#include "VistaCajaVidrio.h"
#include "VistaCajaMetal.h"
#include "VistaBanana.h"
#include "VistaCereza.h"
#include "VistaManzana.h"
#include "VistaPajaroRojo.h"
#include "VistaPajaroVerde.h"
#include "VistaPajaroAzul.h"
#include "VistaHuevoBlanco.h"
#include "VistaHuevoCodorniz.h"
#include "VistaHuevoPoche.h"
#include "VistaHuevoReloj.h"
#include "ConstantesVistaModelo.h"

// Exception Includes
#include "../excepciones/ImagenException.h"

VistaEscenario::VistaEscenario(Escenario* escenario) {
	// Almaceno el escenario
	this->escenario = escenario;
	// Registro la vista del escenario en el escenario del modelo.
	this->escenario->registrarObservador(this);
	// Establezco unas dimenciones estandar
	this->ancho = 1024;
	this->alto = 640;
	gdk_threads_enter();
		this->set_size_request(ancho, alto);
	gdk_threads_leave();

	this->vTiempo = NULL;
}

VistaEscenario::~VistaEscenario() {
	// Libero la memoria de las vistas
	std::list<VistaCuerpo*>::iterator it;
	for(it = this->vCuerpos.begin(); it != this->vCuerpos.end(); ++it) {
		delete (*it);
	}

	if (this->vTiempo != NULL)
		delete this->vTiempo;
}

void VistaEscenario::mover(VistaCuerpo* cuerpo, int x, int y) {
	gdk_threads_enter();
		this->move(*cuerpo, x, y);
	gdk_threads_leave();
}

void VistaEscenario::eliminar(VistaCuerpo* cuerpo) {
	// Elimino el cuerpo del fixed
	gdk_threads_enter();
		this->remove(*cuerpo);
	gdk_threads_leave();
	// Elimino el cuerpo de la lista de vista de cuerpos
	this->vCuerpos.remove(cuerpo);
	// Elimino el cuerpo.
	delete cuerpo;
}

void VistaEscenario::seAjustoTamanio(float ancho, float alto) {
	// Ajusto las dimensiones del fixed al tamaño del escenario.
	this->ancho = ancho * AJUSTE_ESCALA_VISTA;
	this->alto = alto * AJUSTE_ESCALA_VISTA;
	gdk_threads_enter();
		this->set_size_request(this->ancho, this->alto);
	gdk_threads_leave();
}

void VistaEscenario::seEstablecioFondo() {
	this->iniciarImagenFondo();
}

void VistaEscenario::seEstablecioSuelo() {
	this->iniciarImagenSuelo();
}

void VistaEscenario::seAgregoCerdito(Cerdito* cerdito) {
	gdk_threads_enter();
	VistaCerdito* vCerdito = new VistaCerdito(this, cerdito);
	this->vCuerpos.push_back(vCerdito);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoCatapulta(Catapulta* catapulta) {
	gdk_threads_enter();
	VistaCatapulta* vCatapulta = new VistaCatapulta(this, catapulta);
	this->vCuerpos.push_back(vCatapulta);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoMonticulo(Monticulo* monticulo) {
	gdk_threads_enter();
	VistaMonticulo* vMonticulo = new VistaMonticulo(this, monticulo);
	this->vCuerpos.push_back(vMonticulo);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoCajaVidrio(CajaVidrio* caja) {
	gdk_threads_enter();
	VistaCajaVidrio* vCaja = new VistaCajaVidrio(this, caja);
	this->vCuerpos.push_back(vCaja);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoCajaMadera(CajaMadera* caja) {
	gdk_threads_enter();
	VistaCajaMadera* vCaja = new VistaCajaMadera(this, caja);
	this->vCuerpos.push_back(vCaja);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoCajaMetal(CajaMetal* caja) {
	gdk_threads_enter();
	VistaCajaMetal* vCaja = new VistaCajaMetal(this, caja);
	this->vCuerpos.push_back(vCaja);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoManzana(Manzana* manzana) {
	gdk_threads_enter();
	VistaManzana* vManzana = new VistaManzana(this, manzana);
	this->vCuerpos.push_back(vManzana);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoBanana(Banana* banana) {
	gdk_threads_enter();
	VistaBanana* vBanana = new VistaBanana(this, banana);
	this->vCuerpos.push_back(vBanana);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seAgregoCereza(Cereza* cereza) {
	gdk_threads_enter();
	VistaCereza* vCereza = new VistaCereza(this, cereza);
	this->vCuerpos.push_back(vCereza);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoPajaroRojo(PajaroRojo* pajaro) {
	gdk_threads_enter();
	VistaPajaroRojo* vPajaro = new VistaPajaroRojo(this, pajaro);
	this->vCuerpos.push_back(vPajaro);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoPajaroVerde(PajaroVerde* pajaro) {
	gdk_threads_enter();
	VistaPajaroVerde* vPajaro = new VistaPajaroVerde(this, pajaro);
	this->vCuerpos.push_back(vPajaro);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoPajaroAzul(PajaroAzul* pajaro) {
	gdk_threads_enter();
	VistaPajaroAzul* vPajaro = new VistaPajaroAzul(this, pajaro);
	this->vCuerpos.push_back(vPajaro);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoHuevoBlanco(HuevoBlanco* huevo) {
	gdk_threads_enter();
	VistaHuevoBlanco* vHuevo = new VistaHuevoBlanco(this, huevo);
	this->vCuerpos.push_back(vHuevo);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoHuevoCodorniz(HuevoCodorniz* huevo) {
	gdk_threads_enter();
	VistaHuevoCodorniz* vHuevo = new VistaHuevoCodorniz(this, huevo);
	this->vCuerpos.push_back(vHuevo);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoHuevoPoche(HuevoPoche* huevo) {
	gdk_threads_enter();
	VistaHuevoPoche* vHuevo = new VistaHuevoPoche(this, huevo);
	this->vCuerpos.push_back(vHuevo);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::seLanzoHuevoReloj(HuevoReloj* huevo) {
	gdk_threads_enter();
	VistaHuevoReloj* vHuevo = new VistaHuevoReloj(this, huevo);
	this->vCuerpos.push_back(vHuevo);
	show_all();
	gdk_threads_leave();
}

void VistaEscenario::monticuloDestruido() {
	// TODO(alguien) : implementar
}

void VistaEscenario::cerditoMatado() {
	// TODO(alguien) : implementar
}

void VistaEscenario::cerditoMatado(unsigned int idJugador) {
	// TODO(alguien) : implementar
}

void VistaEscenario::partidaGanada() {
	// TODO(alguien) : implementar
}

void VistaEscenario::partidaPerdida() {
	// TODO(alguien) : implementar
}

void VistaEscenario::actualizarTiempo(unsigned int miliseg) {
	gdk_threads_enter();
	if (this->vTiempo == NULL)
		this->vTiempo = new VistaTiempo(this);
	this->vTiempo->setTiempo(miliseg);
	show_all();
	gdk_threads_leave();
}

int VistaEscenario::getAncho() const {
	return this->ancho;
}
int VistaEscenario::getAlto() const {
	return this->alto;
}

void VistaEscenario::iniciarImagenFondo() {
	Glib::RefPtr<Gdk::Pixbuf> buf;
	try {
		buf = Gdk::Pixbuf::create_from_file(this->escenario->getRutaImagenFondo());
	} catch(Glib::Exception& e) {
		throw ImagenException("Error al cargar imagen de fondo.");
	}
	// escalo imagen
	buf = buf->scale_simple(ancho, alto, Gdk::INTERP_BILINEAR);

	// seteo nueva imgen
	this->fondo = new Gtk::Image(buf);
	gdk_threads_enter();
		this->put(*fondo, 0, 0);
	gdk_threads_leave();
}

void VistaEscenario::iniciarImagenSuelo() {
	Glib::RefPtr<Gdk::Pixbuf> buf;
	try {
		buf = Gdk::Pixbuf::create_from_file(this->escenario->getRutaImagenSuelo());
	} catch (Glib::Exception& e) {
		throw ImagenException("Error al cargar imagen del suelo.");
	}
	// escalo imagen
	int nuevoAlto = round((SUELO_ALTO + SUELO_POSICION) * AJUSTE_ESCALA_VISTA);
	buf = buf->scale_simple(ancho, nuevoAlto, Gdk::INTERP_BILINEAR);

	// seteo nueva imgen
	this->suelo =  new Gtk::Image(buf);
	gdk_threads_enter();
		this->put(*suelo, 0, alto - nuevoAlto);
	gdk_threads_leave();
}
