// Header Include.
#include "Monticulo.h"

// Project Includes.
#include "Constantes.h"

Monticulo::Monticulo(b2Body* body) : CuerpoAbstracto(body, M_VIDA) {
	// Paso una referencia de este objeto al body de Box2D
	this->cuerpo->SetUserData(this);
	// Defino la forma del monticulo (triangulo)
	b2PolygonShape polygonShape;
	int32 verticesTriangulo = 3;

	b2Vec2 vertices[3];
	vertices[0].Set(0.0f, 0.0f);		// Vertice inferior izquierdo.
	vertices[1].Set(M_ANCHO, 0.0f);		// Vertice inferior derecho.
	vertices[2].Set((M_ANCHO)/2, M_ALTO);		// Vertice superior.

	polygonShape.Set(vertices, verticesTriangulo);

	// Defino las propiedades del cuerpo
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = 0.8f;
	fixtureDef.friction = 0.3f;
	fixtureDef.filter.categoryBits = CATEGORY_MONTICULO;
	fixtureDef.filter.maskBits = MASK_MONTICULO;
	this->cuerpo->CreateFixture(&fixtureDef);
}

Monticulo::~Monticulo() { }

XMLNode* Monticulo::serialize() {
	// Serializo la posicion del monticulo
	const b2Vec2 vec = this->cuerpo->GetPosition();
	Punto2D p(vec.x, vec.y);
	XMLNode* punto = p.serialize();
	// Creo el nodo para el monticulo
	XMLNode* nodo = new XMLNode("MonticuloHuevos");
	// Agrego el nodo del Punto2D
	nodo->LinkEndChild(punto);
	return nodo;
}

void Monticulo::hydrate(const XMLNode* nodo) {
	// No realiza nada porque se requiere el b2Body.
}
