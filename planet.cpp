// Authors: C. Hohne, J. Woychuk

#include "planet.h"

// Gravitational Constant
const double G = 6.6743e-11;

// Constructor function for planet
Planet::Planet(string name, Vector2 position, Vector2 momentum, std::vector<CelestialBody> orbitTargets, int mass, int radius, Color color, string info) {
	this->name = name;
	this->position = position;
	this->mass = mass;
	this->radius = radius;
	this->color = color;
	this->info = info;

	this->orbitTargets = orbitTargets;
	this->momentum = momentum;
}

// Calculates the current net force on the planet and updates the momentum accordingly
void Planet::updateMomentum(double deltaTime) {

	// Iterate over each object this planet is orbiting and calculate the gravitational force
	Vector2 netForce = Vector2Zero();
	for (const CelestialBody& orbitTarget : orbitTargets) {
		double magnitude = -G * (mass * orbitTarget.mass) / pow(Vector2Distance(orbitTarget.position, position), 2);
		Vector2 direction = Vector2Normalize(orbitTarget.position - position);
		netForce += Vector2Scale(direction, magnitude);
	}

	// Update momentum based on the net force and timestep
	momentum += Vector2Scale(netForce, deltaTime);
}

// Updates the position of the planet based on its current momentum
void Planet::updatePosition(double deltaTime) {
	position += (momentum / mass) * deltaTime;
}