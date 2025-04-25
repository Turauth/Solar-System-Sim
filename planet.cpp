// Authors: C. Hohne, J. Woychuk

#include "planet.h"
#include <cmath>

// Gravitational Constant
const double G = 6.6743e-11;

// Constructor function for planet
Planet::Planet(string name, Vector2 position, CelestialBody orbitTarget, float angle, float velocity, int radius, float size, Color color, 
	string info)
{
	this->name = name;
	this->position = position;
	this->orbitTarget = orbitTarget;
	this->angle = angle;
	this->radius = radius;
	this->size = size;
	this->velocity = velocity;
	this->color = color;
	this->info = info;	
}

// The idea and code for movement of the circles is taken from 
// https://terminalroot.com/how-to-create-a-solar-system-animation-with-cpp-and-raylib/.
void Planet::updatePosition() {
	angle += velocity * .02f;
	position = {
                orbitTarget.position.x + std::cos(angle) * radius,
                orbitTarget.position.y + std::sin(angle) * radius,
            };
}