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
// Rock variables
const char RockSymbol = '#';
int rockSpeed = 1;

// Dwarf variables
int dwarfSpeed = 1;

// Game variables
unsigned long sleepDuration = 200;

vector<GameObject> dwarf;
vector<GameObject> rocks;

unsigned int frameCounter = 0;
unsigned int rockSpawnInterval = 10;

void Update()
{
	COORD direction = { 0, 0 };
	if (kbhit())
	{
		char key = getch();
		switch (key)
		{
		case 'a':
			direction.X = -dwarfSpeed;
			direction.Y = 0;
			break;
		case 'w':
			direction.X = 0;
			direction.Y = -dwarfSpeed;
			break;
		case 'd':
			direction.X = dwarfSpeed;
			direction.Y = 0;
			break;
		case 's':
			direction.X = 0;
			direction.Y = dwarfSpeed;
			break;
		};
	}
	for (randomAccess_iterator dwarfBody = dwarf.begin(); dwarfBody != dwarf.end(); ++dwarfBody)
	{
		dwarfBody->Coordinates.X += direction.X;
		dwarfBody->Coordinates.Y += direction.Y;
	}

	// Update the position of all rocks. Remove any rock that goes outside the window

	for (randomAccess_iterator rock = rocks.begin(); rock != rocks.end(); /* Empty clause so we can delete elements */)
	{
		rock->Coordinates.Y += rockSpeed;
		if (rock->Coordinates.Y > WindowHeight - 1)
		{
			rock = rocks.erase(rock);
		}
		else
		{
			++rock;
		}
	}

	if (frameCounter % rockSpawnInterval == 0)
	{
		// Spawn a new rock at every x frames
		int x = rand() % WindowWidth;
		rocks.push_back(GameObject(x, 0, RockSymbol));
	}
	++frameCounter;
}

void Draw()
{
	ClearScreen(consoleHandle);

	for (const_iterator dwarfBody = dwarf.cbegin(); dwarfBody != dwarf.cend(); ++dwarfBody)
	{
		dwarfBody->Draw(consoleHandle);
	}

	for (const_iterator rock = rocks.cbegin(); rock != rocks.cend(); ++rock)
	{
		rock->Draw(consoleHandle);
	}

}

int main()
{
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo; 
	GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

	srand(time(NULL));

	int dwarfY = WindowHeight - 1;
	int dwarfX = WindowWidth / 2;
	char dwarfSymbol = '*';

	dwarf.push_back(GameObject(dwarfX - 1, dwarfY - 1, dwarfSymbol));
	dwarf.push_back(GameObject(dwarfX + 1, dwarfY - 1, dwarfSymbol));
	dwarf.push_back(GameObject(dwarfX, dwarfY, dwarfSymbol));
	dwarf.push_back(GameObject(dwarfX - 1, dwarfY + 1, dwarfSymbol));
	dwarf.push_back(GameObject(dwarfX + 1, dwarfY + 1, dwarfSymbol));
	

	while (true)
	{
		Update();
		Draw();
		Sleep(sleepDuration);
	}

	return 0;
}