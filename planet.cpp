#include "planet.h"

// Gravitational Constant
const double G = 6.6743e-11;

// Constructor function for planet
Planet::Planet(string name, raylib::Vector2 position, raylib::Vector2 momentum, CelestialBody orbitTarget, int mass, int radius, Color color, string info) {
	this->name = name;
	this->position = position;
	this->mass = mass;
	this->radius = radius;
	this->color = color;
	this->info = info;

	this->orbitTarget = orbitTarget;
	this->momentum = momentum;
}

// Calculates the current force on the planet and updates the momentum accordingly
int Planet::updateMomentum(double deltaTime) {
	// TODO: Implement gravity equation
}

// Updates the position of the planet based on its current momentum
int Planet::updatePosition(double deltaTime) {
	// TODO: Implement position update equation
}