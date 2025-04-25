// Authors: C. Hohne, J. Woychuk

// Description: This Class header file declares the members of the CelestialBody class, including attributes 
// position, color, size, name, and info. Both a specified and a default constructor are declared, as well as
// a function to render informational text on the graphics window.

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

	// Declare a specified constructor.
	CelestialBody(string name, Vector2 position, float size, Color color, string info);

	// Declare an empty default constructor to prevent planet.cpp from throwing a fit.
	CelestialBody();
  
	// Declare the class function that will check whether the mouse position is overlapping with a CelestialBody object 
	// and draw a textbox with its info if it is.
	void RenderInfo(Vector2 mousePosition, Vector2 position) const;
};