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