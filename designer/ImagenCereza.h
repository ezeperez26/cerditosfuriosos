#ifndef _IMAGEN_CEREZA_H_
#define _IMAGEN_CEREZA_H_

// Hierarchy Include.
#include "ImagenFruta.h"

// Designer Project Includes.
#include "ConstantesDiseniador.h"

/**
 * Las instancias de esta clase representan a la vista de una cereza
 * sobre un lienzo.
 */
class ImagenCereza : public ImagenFruta {
public:

	/**
	 * Constructor.
	 * @param x abscisa de la esquina superior derecha de la imagen
	 * @param y ordenada de la esquina superior derecha de la imagen
	 */
	ImagenCereza(int x, int y);

	/**
	 * Destructor.
	 */
	virtual ~ImagenCereza();

	/**
	 * Serializa la imagen.
	 * @param alto del escenario en el que se va a serializar el objeto.
	 * @return nodo con el objeto serializado.
	 */
	XMLNode* serialize(const int altoEscenario) const;
};

#endif
