/*
 * PajaroRojo.h
 *
 *  Created on: 25/10/2012
 *      Author: ezequiel
 */

#ifndef PAJAROROJO_H_
#define PAJAROROJO_H_

// Hierarchy Include.
#include "Pajaro.h"

class PajaroRojo: public Pajaro {
public:
	explicit PajaroRojo(b2Body* body);
	virtual ~PajaroRojo();

	/**************************
	 * DOUBLE DISPATCH METODS *
	 **************************/
	// SUPERFICIES
	void chocarCon(const CajaMadera* caja);

	// PAJAROS
	void chocarCon(const PajaroRojo* pajaro);

	// DISPAROS
	void chocarCon(const HuevoBlanco* huevo);
};

#endif /* PAJAROROJO_H_ */
