// Authors: C. Hohne, J. Woychuk

// Description: This Planet header file specifies that the class inherits from class CelestialBody. The file
// declares the members of the Planet class, including attributes orbitTarget, angle, velocity, and radius, 
// the class'specified constructor, and a function to update position.

#pragma once
#include "celestialBody.h"

class Planet : public CelestialBody {
    
// Define private attributes for orbitTarget, angle, velocity, and radius.
private:
    CelestialBody orbitTarget;
    float angle;
    float velocity;
    float radius;

// Define public methods to make Planet objects and update their positions.
public:
    // The following specified constructor is designed to make Planet objects.
    Planet(string name, Vector2 position, float angle, float velocity, int radius, float size,
        Color color, string info);

    // The following methods update the positions of the bodies based on the unit circle.
    void updatePosition(CelestialBody orbitTarget);
};