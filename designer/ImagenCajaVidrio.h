#ifndef _IMAGEN_CAJA_VIDRIO_H_
#define _IMAGEN_CAJA_VIDRIO_H_

// Hierarchy Include.
#include "ImagenSuperficie.h"

// Designer Project Includes.
#include "ConstantesDiseniador.h"

/**
 * Las instancias de esta clase representan a la vista de una cada de vidrio
 * sobre un lienzo.
 */
class ImagenCajaVidrio : public ImagenSuperficie {
public:

	/**
	 * Constructor.
	 * @param x abscisa de la esquina superior derecha de la imagen
	 * @param y ordenada de la esquina superior derecha de la imagen
	 */
	ImagenCajaVidrio(int x, int y);

	/**
	 * Destructor.
	 */
	virtual ~ImagenCajaVidrio();

	/**
	 * Serializa la imagen.
	 * @param alto del escenario en el que se va a serializar el objeto.
	 * @return nodo con el objeto serializado.
	 */
	XMLNode* serialize(const int altoEscenario) const;
};

#endif
