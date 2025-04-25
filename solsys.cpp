// Authors: C. Hohne, J. Gutierrez, J. Woychuk

#include "celestialBody.h"
#include "planet.h"
#include "raylib.h"
#include <iostream>
#include <vector>

int main()
{
    const int SCREENWIDTH = 1920;
    const int SCREENHEIGHT = 1080;

    // values taken from https://terminalroot.com/how-to-create-a-solar-system-animation-with-cpp-and-raylib/.
    std::vector<float> planetRadii{80, 110, 165, 165, 225, 310, 430, 500, 505, 515};
    std::vector<float> planetSizes{10, 15, 20, 20, 18, 60, 55, 25, 22, 10};
    std::vector<float> planetVelocities{1.607f, 1.174f, 1.f, 1.f, .802f, .434f, .323f, .228f, .182f, 1.151f};
    std::vector<float> planetAngles{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<Color> planetColors{BROWN, YELLOW, GREEN, GRAY, RED, ORANGE, RED, BLUE, BLUE, BLACK, YELLOW};
    std::vector<std::string> names{"Mercury", "Venus", "Earth", "Moon", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Sun"};

    std::vector<std::string> info{
        "Name: Mercury\nMass: .33e24 kg\nDiameter: 4879 km",
        "Name: Venus\nMass: 4.87e24 kg\nDiameter: 12,104 km",
        "Name: Earth\nMass: 5.97e24 kg\nDiameter: 12,756 km",
        "Name: Moon\nMass: .073e24 kg\nDiameter: 3475 km",
        "Name: Mars\nMass: .642e24 kg\nDiameter: 6792 km",
        "Name: Jupiter\nMass: 1898e24 kg\nDiameter: 142,984 km",
        "Name: Saturn\nMass: 568e24 kg\nDiameter: 120,536 km",
        "Name: Uranus\nMass: 86.8e24 kg\nDiameter: 51,118 km",
        "Name: Neptune\nMass: 102e24 kg\nDiameter: 49,528 km",
        "Name: Pluto\nMass: .013e24 kg\nDiameter: 2376 km",
        "Name: Sun\nMass: 1,988,400e24 kg\nDiameter: 1,391,400 km",};

    // Instantiate CelestialBody and Planet objects.
    // CelestialBody::CelestialBody(string name, Vector2 position, float size, Color color, string info) {


    CelestialBody sun(names[10], {SCREENWIDTH/2, SCREENHEIGHT/2}, 60, planetColors[10], info[10]);
    Planet mercury(names[0], {sun.position.x + planetRadii[0], sun.position.y}, sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], planetColors[0], info[0]);
    Planet venus(names[1], {sun.position.x + planetRadii[1], sun.position.y}, sun, planetAngles[1], planetVelocities[1], planetRadii[1], planetSizes[1], planetColors[1], info[1]);
    Planet earth(names[2], {sun.position.x + planetRadii[2], sun.position.y}, sun, planetAngles[2], planetVelocities[2], planetRadii[2], planetSizes[2], planetColors[2], info[2]);
    Planet moon(names[3], {sun.position.x + planetRadii[3], sun.position.y}, sun, planetAngles[3], planetVelocities[3], planetRadii[3], planetSizes[3], planetColors[3], info[3]);
    Planet mars(names[4], {sun.position.x + planetRadii[4], sun.position.y}, sun, planetAngles[4], planetVelocities[4], planetRadii[4], planetSizes[4], planetColors[4], info[4]);
    Planet jupiter(names[5], {sun.position.x + planetRadii[5], sun.position.y}, sun, planetAngles[5], planetVelocities[5], planetRadii[5], planetSizes[5], planetColors[5], info[5]);
    Planet saturn(names[6], {sun.position.x + planetRadii[6], sun.position.y}, sun, planetAngles[6], planetVelocities[6], planetRadii[6], planetSizes[6], planetColors[6], info[6]);
    Planet uranus(names[7], {sun.position.x + planetRadii[7], sun.position.y}, sun, planetAngles[7], planetVelocities[7], planetRadii[7], planetSizes[7], planetColors[7], info[7]);
    Planet neptune(names[8], {sun.position.x + planetRadii[8], sun.position.y}, sun, planetAngles[8], planetVelocities[8], planetRadii[8], planetSizes[8], planetColors[8], info[8]);
    Planet pluto(names[9], {sun.position.x + planetRadii[9], sun.position.y}, sun, planetAngles[9], planetVelocities[9], planetRadii[9], planetSizes[9], planetColors[9], info[9]);

    std::vector<Planet> planets{mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune, pluto};

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Solar System Simulation");
    SetTargetFPS(60);

    // Make a loop that runs continuously until the window close button or ESC key are pressed.
    while (!WindowShouldClose())
    {
        // Draw stuff.
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircleV(sun.position, sun.size, sun.color);
        for (int i{0}; i < 1; ++i)
        {            
            planets[i].updatePosition();
            DrawCircleV(planets[i].position, planets[i].size, planets[i].color);
        }

        EndDrawing();
    }

    // When the window close button or ESC key are pressed, close the window and OpenGL context.
    CloseWindow(); 

    std::cout << planets[0].position.x << std::endl;
    std::cout << planets[0].position.y << std::endl;

    return 0;
}