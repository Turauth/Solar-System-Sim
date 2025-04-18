#pragma once
#include "raylib.h"

#include <string>
using namespace std;

class CelestialBody {
private:

public:
	// Creates a new celestial body
	// (string: name, Vector2: position, int: mass, int: radius, Color: color, string: info)
	CelestialBody(string, Vector2, int, int, Color, string);

	Vector2 position;
	Color color;

	int radius;
	int mass;

	string name;
	string info;
};