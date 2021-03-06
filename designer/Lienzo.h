#ifndef _LIENZO_H_
#define _LIENZO_H_

// C++ Library Includes.
#include <string>
#include <list>
#include <map>

// GTK+ Library Includes.
#include <gtkmm/fixed.h>
#include <gtkmm/eventbox.h>

// Designer Project Includes.
#include "InformableSeleccion.h"
#include "ConstantesDiseniador.h"
#include "ImagenCerdo.h"
#include "ImagenCatapulta.h"
#include "ImagenHuevos.h"
#include "ImagenSuperficie.h"
#include "ImagenCajaMadera.h"
#include "ImagenCajaMetal.h"
#include "ImagenCajaVidrio.h"
#include "ImagenFruta.h"
#include "ImagenBanana.h"
#include "ImagenCereza.h"
#include "ImagenManzana.h"


using std::list;
using std::string;

/**
 * Las instancias de esta clase representan a un contenedor vacio, sobre el cual
 * podemos arrastrar los objetos que integran el escenario del juego.
 */
class Lienzo : public Gtk::Fixed {
public:

	/**
	 * Constructor.
	 */
	Lienzo(int ancho,
			int alto,
			int cantidadJugadores,
			string rutaFondo,
			string rutaSuelo,
			InformableSeleccion* informable);

	/**
	 * Destructor.
	 */
	virtual ~Lienzo();

	/**
	 * @param rutaNivel cargaremos los objetos pertenecientes a un nivel que
	 * se quiere editar
	 */
	void cargarNivel(const string rutaNivel);

	/**
	 * @param rutaNivel guardaremos los objetos pertenecientes al nivel ya
	 * editado
	 */
	void guardarNivel(const string rutaNivel) const;

	/**
	 * @param id identificador de la imagen contenida en este lienzo que se
	 * quiere eliminar
	 */
	void eliminarImagen(string id);

	/**
	 * @return true si la cantidad de jugadores agregados es la
	 * correspondiente al nivel y false en el caso contrario
	 */
	bool cantidadJugadoresValida() const;
	
	/**
	 * @return true si por cada cerdo hay una catapulta y false en el caso
	 * contrario
	 */
	bool cantidadCatapultasValida() const;
	
	/**
	 * @return true si hay un monticulo en el escenario y false en el caso
	 * contrario
	 */
	bool hayMonticulo() const;

protected:
	/**
	 * Recibe informacion de un drag and drop e instancia una imagen
	 * posicionable en funcion de esta.
	 */
	void recibirInformacion(const Glib::RefPtr<Gdk::DragContext>& context,
								int x,
								int y,
								const Gtk::SelectionData& selection_data,
								guint info,
								guint time);

	void setTamanio(const int ancho, const int alto);

private:
	/**
	 * Se le pasa la ruta de una imagen y la escala para ponerla de fondo.
	 */
	void agregarFondo(const string rutaImagen);

	/**
	 * Se le pasa la ruta de una imagen y la escala para ponerla de suelo.
	 */
	void agregarSuelo(const string rutaSuelo);

	/**
	 * Le copia el fondo a una imagen posicionable.
	 * @param x abscisa a partir de la cual queremos copiar el fondo
	 * @param y ordenada a partir de la cual queremos copiar el fondo
	 * @param imagen puntero a la imagen posicionable a la cual le
	 * copiaremos el fondo
	 */
	void copiarFondo(int x, int y, ImagenPosicionable* imagen);

	/**
	 * @param id identificador del posicionable contenido en este lienzo que
	 * se quiere eliminar
	 */
	void eliminarPosicionable(string id);

	/**
	 * Agrega un cerdo en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarCerdo(int x, int y);

	/**
	 * Agrega una catapulta en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarCatapulta(int x, int y);
	
	/**
	 * Agrega un monticulo en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarMonticulo(int x, int y);
	
	/**
	 * Agrega una caja de madera en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarCajaMadera(int x, int y);

	/**
	 * Agrega una caja de metal en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarCajaMetal(int x, int y);

	/**
	 * Agrega una caja de vidrio en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarCajaVidrio(int x, int y);

	/**
	 * Agrega una banana en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarBanana(int x, int y);

	/**
	 * Agrega una cereza en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarCereza(int x, int y);
	
	/**
	 * Agrega una manzana en la posicion indicada por los parametros
	 * @param x abscisa donde queremos agregar la imagen
	 * @param y ordenada donde queremos agregar la imagen
	 */
	void agregarManzana(int x, int y);
	
	/**
	 * Mueve el objeto identificado por el primer parametro hacia el punto,
	 * siempre y cuando no vaya a ocupar la posicion de otro objeto ya
	 * agregado ni a salirse de los limites.
	 * @param x abscisa donde queremos agregar a la imagen
	 * @param y ordenada donde queremos agregar a la imagen
	 */
	void moverObjeto(string id, int x, int y);

	/**
	 * @param x abscisa de la esquina superior derecha del objeto a agregar
	 * @param x ordenada de la esquina superior derecha del objeto a agregar
	 * @param imagen objeto a agregar
	 * @return true si el objeto a agregar coincidira espacialmente con
	 * alguno ya agregado y false en el caso contrario
	 */
	bool coincidenciaOcupacional(int x, int y, ImagenPosicionable* imagen);

	/**
	 * @param x abscisa de la esquina superior derecha del objeto a agregar
	 * @param x ordenada de la esquina superior derecha del objeto a agregar
	 * @param imagen objeto a agregar
	 * @return true si el objeto a agregar esta espacialmente dentro del
	 * escenario y false en el caso contrario
	 */
	bool dentroDeEscenario(int x, int y, ImagenPosicionable* imagen);

	/*
	 * Los siguientes metodos estan sobrecargados para los casos en los que
	 * se carga un nivel desde un archivo.
	 */
	void agregarCerdo(float x, float y);
	void agregarCatapulta(float x, float y);
	void agregarMonticulo(float x, float y);
	void agregarCajaMadera(float x, float y);
	void agregarCajaMetal(float x, float y);
	void agregarCajaVidrio(float x, float y);
	void agregarBanana(float x, float y);
	void agregarCereza(float x, float y);
	void agregarManzana(float x, float y);

	/*
	 * Los siguientes métodos son los de serialización e hidratación.
	 */
	void XMLCargarCerdos(const XMLNode* nodoCerdos);
	void XMLCargarCerdo(const XMLNode* nodoCerdo);
	void XMLCargarMonticulo(const XMLNode* nodoMonticulo);
	void XMLCargarSuperficies(const XMLNode* nodoSuperficies);
	void XMLCargarFrutas(const XMLNode* nodoFrutas);

	void hidratarCoordenadas(const XMLNode* nodo, float& x, float& y);

	XMLNode* XMLSerializarCerdos() const;
	XMLNode* XMLSerializarSuperficies() const;
	XMLNode* XMLSerializarFrutas() const;
	
	/*************
	 * ATRIBUTOS *
	 *************/
	unsigned int cantidadJugadores;
	int ancho;
	int alto;

	InformableSeleccion* informable;

	Gtk::Image* imagenFondo;
	Gtk::Image* imagenSuelo;
	list<Gtk::TargetEntry> listaObjetivos;

	list<ImagenCerdo*> cerdos;
	list<ImagenCatapulta*> catapultas;
	ImagenHuevos* monticulo;
	list<ImagenSuperficie*> superficies;
	list<ImagenFruta*> frutas;

	list<ImagenPosicionable*> posicionables;

	/*********************
	 * PARSER ATTRIBUTES *
	 *********************/
	// Definicion de valores para superficies
	static enum SuperficieValues {
		supNoDefinida,
		supCajaVidrio,
		supCajaMadera,
		supCajaMetal
	} supValues;

	// Definición del mapa de superficies
	typedef std::map<std::string, SuperficieValues> SuperficiesMap;

	// Mapa asociado a los strings de valores enumerados de Superficies.
	static SuperficiesMap mapSuperficies;

	// Definicion de valores para frutas
	static enum FrutasValues {
		fruNoDefinida,
		fruManzana,
		fruBanana,
		fruCereza
	} fruValues;

	// Definición del mapa de frutas
	typedef std::map<std::string, FrutasValues> FrutasMap;

	// Mapa asociado a los strings de valores enumerados de Frutas.
	static FrutasMap mapFrutas;

	/*************************************************
	 * Funciones privadas para inicializar los mapas *
	 *************************************************/
	static SuperficiesMap inicializarMapaSuperficies();
	static FrutasMap inicializarMapaFrutas();
};

#endif
