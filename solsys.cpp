// Authors: C. Hohne, J. Gutierrez, J. Woychuk

// NOTE: Exact values may need to have scaling applied to fit all of the planets on screen at once while also keeping them visible.
// TODO: Add the values for vectors perihelia, maxOrbVel, initPositions, and initMomenta.

#include "celestialBody.h"
#include "planet.h"
#include "raylib.h"
#include <iostream>
#include <vector>

int main(void) {

    // Make vectors to contain some constant values to be used when initializing the planets
    // (https://nssdc.gsfc.nasa.gov/planetary/factsheet/sunfact.html; https://nssdc.gsfc.nasa.gov/planetary/factsheet/). This 
    // is purely for readability and organization.

    // (MASS: kilograms, DISTANCE: meters, TIME: seconds)

    // Perihelia are the distances to the Sun at the closest point in the orbit of each planet. The perigree of the moon will
    // be labeled as its parahelion for container uniformity. The perihelia and perigree are scaled down by a factor of 10^6.
    // For consistency, all planets will begin at their perihelia.

    // Max orbital speeds are taken from https://starlust.org/orbital-parameters-glossary/ and 
    // https://nssdc.gsfc.nasa.gov/planetary/factsheet/plutofact.html.

    //For initPositions, a window size of of 1600x800 is assumed.

    std::vector<std::string> names{"Mercury", "Venus", "Earth", "Moon", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune",
        "Pluto", "Sun"};

    std::vector<const double> perihelia{46, 107.5, 147.1, .363, 206.7, 740.6, 1357.6, 2732.7, 4471.1, 4436.8};
    std::vector<const double> maxOrbVel{58980, 35260, 30290, 26500, 13720, 10180, 7110, 5500, 6100};
    std::vector<Vector2> initPositions{
        {800 + perihelia[0], 400},
        {800 + perihelia[1], 400},
        {800 + perihelia[2], 400},
        {800 + perihelia[3], 400},
        {800 + perihelia[4], 400},
        {800 + perihelia[5], 400},
        {800 + perihelia[6], 400},
        {800 + perihelia[7], 400},
        {800 + perihelia[8], 400},
        {800 + perihelia[9], 400},
        {800, 400}};
    std::vector<Vector2> initMomenta{}; // This vector is not yet populated.
    
    std::vector<const double> masses{33e22, 487e22, 597e22, 73e21, 642e21, 1898e24, 568e24, 868e23, 102e24, 
        13e21,1988400e24};
    std::vector<int> radii{4879/2, 12104/2, 12756/2, 3475/2, 6792/2, 142984/2, 120536/2, 51118/2, 49528/2, 2376/2, 695700};
    std::vector<Color> colors{BROWN, YELLOW, GREEN, GRAY, RED, ORANGE, RED, BLUE, BLUE, BLACK, YELLOW};
    std::vector<std::string> info{
        "Name: Mercury\nMass: .33e24 kg\nDiameter: 4879 m",
        "Name: Venus\nMass: 4.87e24 kg\nDiameter: 12,104 m",
        "Name: Earth\nMass: 5.97e24 kg\nDiameter: 12,756 m",
        "Name: Moon\nMass: .073e24 kg\nDiameter: 3475 m",
        "Name: Mars\nMass: .642e24 kg\nDiameter: 6792 m",
        "Name: Jupiter\nMass: 1898e24 kg\nDiameter: 142,984 m",
        "Name: Saturn\nMass: 568e24 kg\nDiameter: 120,536 m",
        "Name: Uranus\nMass: 86.8e24 kg\nDiameter: 51,118 m",
        "Name: Neptune\nMass: 102e24 kg\nDiameter: 49,528 m",
        "Name: Pluto\nMass: .013e24 kg\nDiameter: 2376 m",
        "Name: Sun\nMass: 1,988,400e24 kg\nDiameter: 1,391,400 m",
    };


    // Instantiate CelestialBody and Planet objects.
    CelestialBody sun(names[10], initPositions[10], masses[10], radii[10], colors[10], info[10]);
    Planet mercury(names[0], initPositions[0], initMomenta[0], sun, masses[0], radii[0], colors[0], info[0]);
    Planet venus(names[1], initPositions[1], initMomenta[1], sun, masses[1], radii[1], colors[1], info[1]);
    Planet earth(names[2], initPositions[2], initMomenta[2], sun, masses[2], radii[2], colors[2], info[2]);
    Planet moon(names[3], initPositions[3], initMomenta[3], earth, masses[3], radii[3], colors[3], info[3]);
    Planet mars(names[4], initPositions[4], initMomenta[4], sun, masses[4], radii[4], colors[4], info[4]);
    Planet jupiter(names[5], initPositions[5], initMomenta[5], sun, masses[5], radii[5], colors[5], info[5]);
    Planet saturn(names[6], initPositions[6], initMomenta[6], sun, masses[6], radii[6], colors[6], info[6]);
    Planet uranus(names[7], initPositions[7], initMomenta[7], sun, masses[7], radii[7], colors[7], info[7]);
    Planet neptune(names[8], initPositions[8], initMomenta[8], sun, masses[8], radii[8], colors[8], info[8]);
    Planet pluto(names[9], initPositions[9], initMomenta[9], sun, masses[9], radii[9], colors[9], info[9]);

    // The following line was made to test compilation which is not working yet.
    std::cout << initPositions[0].y << std::endl;
    
    return 0;
}