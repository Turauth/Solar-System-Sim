// Authors: C. Hohne, J. Woychuk

#include "celestialBody.h"

// Implement the specified constructor.
CelestialBody::CelestialBody(string name, Vector2 position, float size, Color color, string info)
{
	this->name = name;
	this->position = position;
	this->size = size;
	this->color = color;
	this->info = info;
}

// Implement the empty default constructor to prevent planet.cpp from throwing a fit
CelestialBody::CelestialBody()
{
	name = "";
	position = Vector2Zero(); // Vector with components value 0.0f.
	size = 0;
	color = Color();
	info = "";
}

// Checks if the mouse position is overlapping with the celestial body and draws a textbox with its info
void CelestialBody::RenderInfo(Vector2 mousePos, Vector2 position) const {
	if (Vector2Distance(position, mousePos) <= size) {
		Vector2 corner = { position.x - size - 20, position.y - (size + 90) };
		//std::cout << position.x << '\t' << position.y << std::endl;

		DrawRectangle(corner.x, corner.y, 200, 80, ColorAlpha(BLACK, 0.75f));
		DrawText(TextFormat("%s", info.c_str()), corner.x + 5, corner.y + 5, 20, RAYWHITE);
	}
}