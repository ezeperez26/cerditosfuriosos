#ifndef _IMAGEN_CAJA_METAL_H_
#define _IMAGEN_CAJA_METAL_H_
#include "ImagenPosicionable.h"
#include "ConstantesDiseniador.h"

/**
 * Las instancias de esta clase representan a la vista de una cada de metal
 * sobre un lienzo.
 */
class ImagenCajaMetal : public ImagenPosicionable {
	public:
	
		/**
		 * Constructor.
		 * @param x abscisa de la esquina superior derecha de la imagen
		 * @param y ordenada de la esquina superior derecha de la imagen
		 */
		ImagenCajaMetal(int x, int y);
		
		/**
		 * Destructor.
		 */
		virtual ~ImagenCajaMetal();
};

#endif
