// Authors: C. Hohne, J. Woychuk

#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include <string>
#include <iostream>
using namespace std;

class CelestialBody {
public:
	// Define attributes that will be used by classes and the main function.
	Vector2 position;
	Color color;
	float size;
	string name;
	string info;

	// Define a specified constructor.
	CelestialBody(string name, Vector2 position, float size, Color color, string info);
  
	void RenderInfo(Vector2 mousePosition, Vector2 position) const;
	
	// Define an empty default constructor to prevent planet.cpp from throwing a fit.
	CelestialBody();
};