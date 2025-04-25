//Authors: C. Hohne, J. Woychuk

#pragma once
#include "celestialBody.h"

class Planet : public CelestialBody {
    
// Define a private attributes for 
private:
    CelestialBody orbitTarget;
    float angle;
    float velocity;

// Define public methods to 
public:
    float radius;

    // The following specified constructor is designed to make Planet objects.
    Planet(string name, Vector2 position, CelestialBody orbitTarget, float angle, float velocity, int radius, float size,
        Color color, string info);

    // Updates the position of the planet based on its current momentum
    // (double: deltaTime)
    void updatePosition();
};