// Authors: C. Hohne, J. Gutierrez, J. Woychuk

#include "celestialBody.h"
#include "planet.h"
#include "raylib.h"
#include <iostream>
#include <vector>

int main()
{
    // values taken from https://terminalroot.com/how-to-create-a-solar-system-animation-with-cpp-and-raylib/.
    std::vector<float> planetRadii{80};
    std::vector<float> planetSizes{10};
    std::vector<float> planetVelocities{1.607f};
    std::vector<Color> planetColors{BROWN, YELLOW, GREEN, GRAY, RED, ORANGE, RED, BLUE, BLUE, BLACK, YELLOW};
    std::vector<float> planetAngles{0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    std::vector<std::string> names{"Mercury", "Venus", "Earth", "Moon", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Sun"};
    std::vector<Vector2> initPositions{
        {500 + 45, 500},
        {500 + 65, 500},
        {500 + 90, 500},
        {500 + 110, 500},
        {500 + 130, 500},
        {500 + 170, 500},
        {500 + 225, 500},
        {500 + 280, 500},
        {500 + 335, 500},
        {500 + 360, 500},
        {500, 500}};

    std::vector<float> masses{33e22, 487e22, 597e22, 73e21, 642e21, 1898e24, 568e24, 868e23, 102e24, 13e21, 1988400e24};
    std::vector<float> scaledDiameters{10, 20, 20, 10, 20, 40, 40, 30, 30, 10, 70};
    std::vector<Color> colors{BROWN
    std::vector<std::string> info{
        "Name: Mercury\nMass: .33e24 kg\nDiameter: 4879 m",
        "Name: Venus\nMass: 4.87e24 kg\nDiameter: 12,104 m",
        "Name: Earth\nMass: 5.97e24 kg\nDiameter: 12,756 m",
        "Name: Moon\nMass: .073e24 kg\nDiameter: 3475 m",
        "Name: Mars\nMass: .642e24 kg\nDiameter: 6792 m",
        "Name: Jupiter\nMass: 1898e24 kg\nDiameter: 142,984 m",
        "Name: Saturn\nMass: 568e24 kg\nDiameter: 120,536 m",
        "Name: Uranus\nMass: 86.8e24 kg\nDiameter: 51,118 m",
        "Name: Neptune\nMass: 102e24 kg\nDiameter: 49,528 m",
        "Name: Pluto\nMass: .013e24 kg\nDiameter: 2376 m",
        "Name: Sun\nMass: 1,988,400e24 kg\nDiameter: 1,391,400 m",
    };
    std::vector<float> maxOrbVel{58980, 35260, 30290, 108.2, 26500, 13720, 10180, 7110, 5500, 6100};
    std::vector<Vector2> velocities{
        {0, -masses[0] * maxOrbVel[0]},
        {0, -masses[1] * maxOrbVel[1]},
        {0, -masses[2] * maxOrbVel[2]},
        {0, -masses[3] * maxOrbVel[3]},
        {0, -masses[4] * maxOrbVel[4]},
        {0, -masses[5] * maxOrbVel[5]},
        {0, -masses[6] * maxOrbVel[6]},
        {0, -masses[7] * maxOrbVel[7]},
        {0, -masses[8] * maxOrbVel[8]},
        {0, -masses[9] * maxOrbVel[9]}};

    // Instantiate CelestialBody and Planet objects.
    // Planet(string name, Vector2 position, CelestialBody orbitTarget, float angle, float velocity, int radius, float size,
        // Color color, string info);
    CelestialBody sun(names[10], initPositions[10], masses[10], 60, colors[10], info[10]);
    Planet mercury(names[0], initPositions[0], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[0], info[0]);
    Planet venus(names[1], initPositions[1], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[1], info[1]);
    Planet earth(names[2], initPositions[2], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[2], info[2]);
    Planet moon(names[3], initPositions[3], earth, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[3], info[3]);
    Planet mars(names[4], initPositions[4], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[4], info[4]);
    Planet jupiter(names[5], initPositions[5], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[5], info[5]);
    Planet saturn(names[6], initPositions[6], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[6], info[6]);
    Planet uranus(names[7], initPositions[7], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[7], info[7]);
    Planet neptune(names[8], initPositions[8], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[8], info[8]);
    Planet pluto(names[9], initPositions[9], sun, planetAngles[0], planetVelocities[0], planetRadii[0], planetSizes[0], colors[9], info[9]);

    std::vector<Planet> planets{mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune, pluto};

    // Make a window with a certain width and height, and set it to display at 60 FPS.
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Solar System Simulation");
    SetTargetFPS(60);
    double deltaTime = 0;

    // Make a loop that runs continuously until the window close button or ESC key are pressed.
    while (!WindowShouldClose())
    {
        deltaTime = GetTime() - deltaTime;

        // Draw stuff.
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(sun.position, sun.radius, sun.color);
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