// Define some constant values to be used when initializing the planets
// This is purely for readability and organization

// VALUES FROM https://nssdc.gsfc.nasa.gov/planetary/planetfact.html
// (MASS: kilograms, DISTANCE: meters, TIME: seconds)
const double SUN_MASS = 1.9884e30;
const double SUN_RADIUS = 6.957e8;

// Perihelion is the distance to the Sun at the closest point in the orbit.
// For consistency, all planets will begin at the perihelion.
const double EARTH_MASS = 5.9722e24;
const double EARTH_RADIUS = 6.371e6;
const double EARTH_PERIHELION = 1.47095e11;
const double EARTH_MAX_VELOCITY = 3.029e4;

// NOTE: Exact values may need to have scaling applied to fit all of the planets on screen at once while also keeping them visible.
// TODO: Add the values for the rest of the planets


// As of 4/22/25, 7:16 pm, I made lines 21-67 before I saw lines 1-17 of this file. I have some questions,
#include "celestialBody.h"
#include "planet.h"
#include "raylib.h"
#include <iostream>
#include <vector>

int main {

    // Make vectors to contain object parameters.
    std::vector<std::string> names{"Mercury", "Venus", "Earth", "Moon", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune",
        "Pluto", "Sun"};
    // std::vector<raylin::Vector2> initPositions{};
    // std::vector<raylin::Vector2> initMomenta{};
    std::vector<int> masses{33*10^22, 487*10^22, 597*10^22, 73*10^21, 642*10^21, 1898*10^24, 568*10^24, 868*10^23, 102*10^24, 
        13*10^21,10^24};
    std::vector<int> radii{4879/2, 12104/2, 12756/2, 3475/2, 6792/2, 142984/2, 120536/2, 51118/2, 49528/2, 2376/2, 695700};
    std::vector<Color> colors{BROWN, YELLOW, GREEN, GRAY, RED, ORANGE, RED, BLUE, BLUE, BLACK, YELLOW};
    std::vector<std::string> info{
        "Name: Mercury\nMass: .33*10^24 kg\nDiameter: 4879 m",
        "Name: Venus\nMass: 4.87*10^24 kg\nDiameter: 12,104 m",
        "Name: Earth\nMass: 5.97*10^24 kg\nDiameter: 12,756 m",
        "Name: Moon\nMass: .073*10^24 kg\nDiameter: 3475 m",
        "Name: Mars\nMass: .642*10^24 kg\nDiameter: 6792 m",
        "Name: Jupiter\nMass: 1898*10^24 kg\nDiameter: 142,984 m",
        "Name: Saturn\nMass: 568*10^24 kg\nDiameter: 120,536 m",
        "Name: Uranus\nMass: 86.8*10^24 kg\nDiameter: 51,118 m",
        "Name: Neptune\nMass: 102*10^24 kg\nDiameter: 49,528 m",
        "Name: Pluto\nMass: .013*10^24 kg\nDiameter: 2376 m",
        "Name: Sun\nMass: 10^24 kg\nDiameter: 1,391,400 m",
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
    
    return 0;
}