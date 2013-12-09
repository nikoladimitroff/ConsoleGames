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
// Block variables
const char BlockSymbol = '-';
int blockSpeed = 1;

// Ball variables
int ballSpeed = 1;

// Platform variables
int platformSpeed = 1;
int platformLength = 5;

// Game variables
unsigned long sleepDuration = 200;

GameObject ball(WindowWidth / 2, WindowHeight / 2, '*');
vector<GameObject> blocks;
vector<GameObject> platform;

unsigned int blockSpawnInterval = 10;

void Update()
{
	COORD direction = { 0, 0 };
	if (kbhit())
	{
		char key = getch();
		switch (key)
		{
		case 'a':
			direction.X = -ballSpeed;
			break;
		case 'd':
			direction.X = ballSpeed;
			break;;
		};
	}
	for (randomAccess_iterator platformBody = platform.begin(); platformBody != platform.end(); ++platformBody)
	{
		platformBody->Coordinates.X += direction.X;
		platformBody->Coordinates.Y += direction.Y;
	}

	ball.Coordinates.Y += ballSpeed;
	if (ball.Coordinates.Y >= WindowHeight - 1 || ball.Coordinates.Y <= 0)
	{
		ballSpeed = -ballSpeed;
	}

	// Loop trough all blocks
	for (randomAccess_iterator block = blocks.begin(); block != blocks.end(); ++block)
	{
		// Remove any block that is hit by the ball
		// Implement unit collision
	}
}

void Draw()
{
	ClearScreen(consoleHandle);

	for (const_iterator platformBody = platform.cbegin(); platformBody != platform.cend(); ++platformBody)
	{
		platformBody->Draw(consoleHandle);
	}

	for (const_iterator block = blocks.cbegin(); block != blocks.cend(); ++block)
	{
		block->Draw(consoleHandle);
	}

	ball.Draw(consoleHandle);

}

int main()
{
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );

	srand(time(NULL));

	int platformY = WindowHeight - 1;
	int platformX = WindowWidth / 2 - platformLength / 2;
	char platformSymbol = '-';

	for (int i = 0; i < platformLength; i++)
	{
		platform.push_back(GameObject(platformX + i, platformY, platformSymbol));
	}


	// Generate blocks
	int blocksPerColumn = 3;
	for (int i = 0; i < WindowWidth - 1; i++)
	{
		for (int j = 0; j < blocksPerColumn; j++)
		{
			blocks.push_back(GameObject(i, j, BlockSymbol));
		}
	}

	while (true)
	{
		Update();
		Draw();
		Sleep(sleepDuration);
	}

	return 0;
}