// Authors: C. Hohne, J. Woychuk

#include "celestialBody.h"

// Implement the specified constructor.
CelestialBody::CelestialBody(string name, Vector2 position, float size, Color color, string info)
{
	this->name = name;
	this->position = position;
	this->size = size;
	this->color = color;
	this->info = info;
}

// Implement the empty default constructor to prevent planet.cpp from throwing a fit
CelestialBody::CelestialBody()
{
	name = "";
	position = Vector2Zero(); // Vector with components value 0.0f.
	color = Color();
	info = "";
}