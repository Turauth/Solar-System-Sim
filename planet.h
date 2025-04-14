// Add header guards (https://www.learncpp.com/cpp-tutorial/header-guards/).
#ifndef PLANET_H
#define PLANET_H

// Allow the use of std::string (https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/).
#include "celestialBody.h"

class Planet : public CelestialBody {
    // Define a private attributes for velocity and the body that the planet is orbiting.
    private:
        std::string orbitTarget {};
        double velocity {};
    
    // Define public methods to calculate the force acting on and the changes in position and velocity of a given planet. The
    // parameters of these methods will need to be added.
    public:
        double calcForce();
        double calcPosition();
        double calcVelocity();
}

// Add header guard (https://www.learncpp.com/cpp-tutorial/header-guards/).
#endif