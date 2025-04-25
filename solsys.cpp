// Authors: C. Hohne, J. Gutierrez, J. Woychuk

// Description; This is the main file. Vectors are defined with predefined attributes for the Sun, Moon, and planets. Sun, Moon, and Planet objects are instantiated. A window
// is instantiated. The celestial bodies are drawn, and a function is called to display text when the cursor hovers over a body. Pressing the spacebar pauses and starts the
// animation.

#include "celestialBody.h"
#include "planet.h"
#include "raylib.h"
#include <iostream>
#include <vector>

int main()
{
    // Set graphics window dimensions.
    const int SCREENWIDTH = 1920;
    const int SCREENHEIGHT = 1080;

    // Planet radii, display sizes, and velocities are taken from https://terminalroot.com/how-to-create-a-solar-system-animation-with-cpp-and-raylib/. Vectors planetRadii,
    // planetSizes, planetVelocities, planetAngles, planetColors, names, and info will be used to instantiate CelestialBody and Planet objects.
    std::vector<float> planetRadii{80, 110, 165, 30, 225, 310, 430, 500, 505, 515};
    std::vector<float> planetSizes{10, 15, 20, 5, 18, 60, 55, 25, 22, 10};
    std::vector<float> planetVelocities{1.607f, 1.174f, 1.f, 5, .802f, .434f, .323f, .228f, .182f, .151f};
    std::vector<float> planetAngles{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Planet colors are based on https://ar.inspiredpencil.com/pictures-2023/pictues-of-the-planets-in-color and 
    // https://ar.inspiredpencil.com/pictures-2023/mercury-planet-color.
    std::vector<Color> planetColors{BROWN, { 255, 200, 0, 255 }, DARKGREEN, WHITE, RED, ORANGE, RED, DARKBLUE, BLUE, 
        GRAY, YELLOW};
    std::vector<std::string> names{"Mercury", "Venus", "Earth", "Moon", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Sun"};

    // Planet diameters taken from https://nssdc.gsfc.nasa.gov/planetary/factsheet/. Planet types taken from
    // https://nineplanets.org/the-planets-in-order/.
    std::vector<std::string> info{
        "Name: Mercury\nType: Terrestrial\nDiameter: 4879 km",
        "Name: Venus\nType: Terrestrial\nDiameter: 12,104 km",
        "Name: Earth\nType: Terrestrial\nDiameter: 12,756 km",
        "Name: Moon\nType: Moon\nDiameter: 3475 km",
        "Name: Mars\nType: Terrestrial\nDiameter: 6792 km",
        "Name: Jupiter\nType: Gas Giant\nDiameter: 142,984 km",
        "Name: Saturn\nType: Gas Giant\nDiameter: 120,536 km",
        "Name: Uranus\nType: Ice Giant\nDiameter: 51,118 km",
        "Name: Neptune\nType: Ice Giant\nDiameter: 49,528 km",
        "Name: Pluto\nType: Dwarf Planet\nDiameter: 2376 km",
        "Name: Sun\nType: Star\nDiameter: 1,391,400 km",};

    // Instantiate CelestialBody and Planet objects. The planet radii are the radii of their orbits about the sun.
    CelestialBody sun(names[10], {SCREENWIDTH/2, SCREENHEIGHT/2}, 60, planetColors[10], info[10]);
    Planet mercury(names[0], {sun.position.x + planetRadii[0], sun.position.y}, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], planetColors[0], info[0]);
    Planet venus(names[1], {sun.position.x + planetRadii[1], sun.position.y}, planetAngles[1], planetVelocities[1], planetRadii[1], planetSizes[1], planetColors[1], info[1]);
    Planet earth(names[2], {sun.position.x + planetRadii[2], sun.position.y}, planetAngles[2], planetVelocities[2], planetRadii[2], planetSizes[2], planetColors[2], info[2]);
    Planet moon(names[3], {earth.position.x + planetRadii[3], earth.position.y}, planetAngles[3], planetVelocities[3], planetRadii[3], planetSizes[3], planetColors[3], info[3]);
    Planet mars(names[4], {sun.position.x + planetRadii[4], sun.position.y}, planetAngles[4], planetVelocities[4], planetRadii[4], planetSizes[4], planetColors[4], info[4]);
    Planet jupiter(names[5], {sun.position.x + planetRadii[5], sun.position.y}, planetAngles[5], planetVelocities[5], planetRadii[5], planetSizes[5], planetColors[5], info[5]);
    Planet saturn(names[6], {sun.position.x + planetRadii[6], sun.position.y}, planetAngles[6], planetVelocities[6], planetRadii[6], planetSizes[6], planetColors[6], info[6]);
    Planet uranus(names[7], {sun.position.x + planetRadii[7], sun.position.y}, planetAngles[7], planetVelocities[7], planetRadii[7], planetSizes[7], planetColors[7], info[7]);
    Planet neptune(names[8], {sun.position.x + planetRadii[8], sun.position.y}, planetAngles[8], planetVelocities[8], planetRadii[8], planetSizes[8], planetColors[8], info[8]);
    Planet pluto(names[9], {sun.position.x + planetRadii[9], sun.position.y}, planetAngles[9], planetVelocities[9], planetRadii[9], planetSizes[9], planetColors[9], info[9]);

    std::vector<Planet> planets{mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune, pluto};

    // Initialize the graphics window.
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Solar System Simulation");
    SetTargetFPS(60);
    bool isPaused = false;

    // Make a loop that runs continuously until the window close button or ESC key are pressed.
    while (!WindowShouldClose())
    {
        // Input
        if (IsKeyPressed(KEY_SPACE)) {
            isPaused = !isPaused;
        }

        Vector2 mousePos = GetMousePosition();

        // Draw stuff.
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircleV(sun.position, sun.size, sun.color);

        // For each planet object, render it on the graphics window and update its position.
        for (int i{0}; i < 10; ++i)
        {   
            // Only update positions if the program is unpaused. If the moon's position is being updated, set 
            // it to orbit around the earth and increase its angle more than the other planets. 
            if (!isPaused) {
                if (i != 3)
                    planets[i].updatePosition(sun);
                if (i == 3)
                {
                    planets[i].updatePosition(planets[i - 1]);
                }
            }
            DrawCircleV(planets[i].position, planets[i].size, planets[i].color);
        }
      
        // Render informational text after planets have been drawn
        for (int i{ 0 }; i < 10; ++i)
        {
            planets[i].RenderInfo(mousePos, planets[i].position);
        }
        sun.RenderInfo(mousePos, sun.position);

        EndDrawing();
    }

    // When the window close button or ESC key are pressed, close the window.
    CloseWindow();

    return 0;
}