// Authors: C. Hohne, J. Woychuk

#include "celestialBody.h"

// Constructor function for celestial body
CelestialBody::CelestialBody(string name, Vector2 position, int mass, int radius, Color color, string info) {
	this->name = name;
	this->position = position;
	this->mass = mass;
	this->radius = radius;
	this->color = color;
	this->info = info;
}

// Empty default constructor to prevent planet.cpp from throwing a fit
CelestialBody::CelestialBody() {
	name = "";
	position = Vector2Zero(); // Vector with components value 0.0f.
	mass = 0;
	radius = 0;
	color = Color();
	info = "";
}