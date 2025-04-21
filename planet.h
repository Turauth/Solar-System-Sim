// Add header guards (https://www.learncpp.com/cpp-tutorial/header-guards/).
#ifndef PLANET_H
#define PLANET_H

#include "celestialBody.h"

class Planet : public CelestialBody {
    // Define a private attributes for velocity and the body that the planet is orbiting.
private:
    raylib::Vector2 momentum;
    CelestialBody orbitTarget;

    // Define public methods to calculate the force acting on and the changes in position and velocity of a given planet. The
    // parameters of these methods will need to be added.
public:
    // Creates a new planet
    // (string: name, Vector2: position, Vector2: momentum, CelestialBody: orbitTarget, int: mass, int: radius, Color: color, string: info)
    Planet(string, raylib::Vector2, raylib::Vector2, CelestialBody, int, int, Color, string);

    // Calculates the current force on the planet and updates the momentum accordingly
    // (double: deltaTime)
    int updateMomentum(double);

    // Updates the position of the planet based on its current momentum
    // (double: deltaTime)
    int updatePosition(double);
};

// Add header guard (https://www.learncpp.com/cpp-tutorial/header-guards/).
#endif