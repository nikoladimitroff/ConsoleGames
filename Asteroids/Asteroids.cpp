#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>

#include "ConsoleGaming.h"

using namespace std;

HANDLE consoleHandle;

typedef vector<GameObject>::iterator randomAccess_iterator;
typedef vector<GameObject>::const_iterator const_iterator;

// Window constants
const int WindowWidth = 70;
const int WindowHeight = 30;
// Asteroid variables
const char AsteroidSymbol = '#';
int asteroidSpeed = 1;

// Ship variables
int shipSpeed = 1;

// Game variables
unsigned long sleepDuration = 200;

vector<GameObject> ship;
vector<GameObject> asteroids;

unsigned int frameCounter = 0;
unsigned int asteroidSpawnInterval = 10;

void Update()
{
	COORD direction = { 0, 0 };
	if (kbhit())
	{
		char key = getch();
		switch (key)
		{
		case 'a':
			direction.X = -shipSpeed;
			direction.Y = 0;
			break;
		case 'w':
			direction.X = 0;
			direction.Y = -shipSpeed;
			break;
		case 'd':
			direction.X = shipSpeed;
			direction.Y = 0;
			break;
		case 's':
			direction.X = 0;
			direction.Y = shipSpeed;
			break;
		};
	}
	for (randomAccess_iterator shipBody = ship.begin(); shipBody != ship.end(); ++shipBody)
	{
		shipBody->Coordinates.X += direction.X;
		shipBody->Coordinates.Y += direction.Y;
	}

	// Update the position of all asteroids. Remove any asteroid that goes outside the window

	for (randomAccess_iterator asteroid = asteroids.begin(); asteroid != asteroids.end(); /* Empty clause so we can delete elements */)
	{
		asteroid->Coordinates.X -= asteroidSpeed;
		if (asteroid->Coordinates.X <= 0)
		{
			asteroid = asteroids.erase(asteroid);
		}
		else
		{
			++asteroid;
		}
	}

	if (frameCounter % asteroidSpawnInterval == 0)
	{
		// Spawn a new asteroid at every x frames
		int y = rand() % WindowHeight;
		asteroids.push_back(GameObject(WindowWidth - 1, y, AsteroidSymbol));
	}
	++frameCounter;
}

void Draw()
{
	ClearScreen(consoleHandle);

	for (const_iterator shipBody = ship.cbegin(); shipBody != ship.cend(); ++shipBody)
	{
		shipBody->Draw(consoleHandle);
	}

	for (const_iterator asteroid = asteroids.cbegin(); asteroid != asteroids.cend(); ++asteroid)
	{
		asteroid->Draw(consoleHandle);
	}

}

int main()
{
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );

	srand(time(NULL));

	int shipY = WindowHeight / 2;
	int shipX = 1;
	char shipSymbol = '*';

	ship.push_back(GameObject(shipX - 1, shipY - 1, shipSymbol));
	ship.push_back(GameObject(shipX + 1, shipY - 1, shipSymbol));
	ship.push_back(GameObject(shipX, shipY, shipSymbol));
	ship.push_back(GameObject(shipX - 1, shipY + 1, shipSymbol));
	ship.push_back(GameObject(shipX + 1, shipY + 1, shipSymbol));
	

	while (true)
	{
		Update();
		Draw();
		Sleep(sleepDuration);
	}

	return 0;
}