#pragma once
#include "raylib.h"
#include "Vector2.hpp"

#include <string>
using namespace std;

class CelestialBody {
private:

public:
	// Creates a new celestial body
	// (string: name, Vector2: position, int: mass, int: radius, Color: color, string: info)
	CelestialBody(string, raylib::Vector2, int, int, Color, string);

	// Empty default constructor to prevent planet.cpp from throwing a fit
	CelestialBody();

	raylib::Vector2 position;
	Color color;

	int radius;
	int mass;

	string name;
	string info;
};