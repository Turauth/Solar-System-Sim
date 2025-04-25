// Authors: C. Hohne, J. Woychuk

#include "celestialBody.h"

// Constructor function for celestial body
CelestialBody::CelestialBody(string name, Vector2 position, float size, int radius, Color color, string info) {
	this->name = name;
	this->position = position;
	this->radius = radius;
	this->size = size;
	this->color = color;
	this->info = info;
}

// Empty default constructor to prevent planet.cpp from throwing a fit
CelestialBody::CelestialBody() {
	name = "";
	position = Vector2Zero(); // Vector with components value 0.0f.
	radius = 0;
	color = Color();
	info = "";
}