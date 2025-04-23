//Authors: C. Hohne, J. Woychuk

#pragma once
#include "celestialBody.h"

class Planet : public CelestialBody {
    // Define a private attributes for velocity and the body that the planet is orbiting.
private:
    Vector2 momentum;
    CelestialBody orbitTarget;

    // Define public methods to calculate the force acting on and the changes in position and velocity of a given planet. The
    // parameters of these methods will need to be added.
public:
    // Creates a new planet
    // (string: name, Vector2: position, Vector2: momentum, CelestialBody: orbitTarget, int: mass, int: radius, Color: color, string: info)
    Planet(string, Vector2, Vector2, CelestialBody, int, int, Color, string);

    // Calculates the current force on the planet and updates the momentum accordingly
    // (double: deltaTime)
    void updateMomentum(double);

    // Updates the position of the planet based on its current momentum
    // (double: deltaTime)
    void updatePosition(double);
};