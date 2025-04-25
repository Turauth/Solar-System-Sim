// Authors: C. Hohne, J. Woychuk

#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include <string>
using namespace std;

class CelestialBody {
private:

public:
	// Creates a new celestial body
	CelestialBody(string name, Vector2 position, float size, int radius, Color color, string info);
	
	// Empty default constructor to prevent planet.cpp from throwing a fit
	CelestialBody();
	Vector2 position;
	Color color;

	int radius;
	float size;

	string name;
	string info;
};