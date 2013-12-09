#include <iostream>
#include <vector>
#include <iostream>
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
// Snake
const int SnakeSpeed = 1;
const int SnakeStartingLength = 5;
const char SnakeSymbol = '*',
	//Fruit
		FruitSymbol = '+';
// Game variables
unsigned long sleepDuration = 200;
vector<GameObject> snake;
vector<GameObject> fruit;

COORD direction = { 1, 0 };

void Update()
{
	// Save the tail, we might need it later.
	GameObject tail = *(snake.end() - 1);

	for (randomAccess_iterator i = snake.end() - 1; i != snake.begin(); --i)
	{
		GameObject next = *(i - 1);
		i->UpdateCoordinates(next.Coordinates);
	}

	if (kbhit())
	{
		char key = getch();
		switch (key)
		{
		case 'a':
			direction.X = -SnakeSpeed;
			direction.Y = 0;
			break;
		case 'w':
			direction.X = 0;
			direction.Y = -SnakeSpeed;
			break;
		case 'd':
			direction.X = SnakeSpeed;
			direction.Y = 0;
			break;
		case 's':
			direction.X = 0;
			direction.Y = SnakeSpeed;
			break;
		};
	}

	snake.begin()->Coordinates.X += direction.X;
	snake.begin()->Coordinates.Y += direction.Y;

	GameObject head = *snake.begin();
	for (randomAccess_iterator i = fruit.begin(); i != fruit.end(); ++i)
	{
		if (head.Coordinates.X == i->Coordinates.X && head.Coordinates.Y == i->Coordinates.Y)
		{
			// Remove the old fruit, increase the snake's size
			fruit.erase(i);
			snake.push_back(tail);

			// Add a new fruit
			int x = rand() % WindowWidth;
			int y = rand() % WindowHeight;
			fruit.push_back(GameObject(x, y, FruitSymbol));

			sleepDuration *= (sleepDuration > 50) * 0.1 + 0.9;
			// Break, since you can't eat more than one fruit at the same time.
			break;
		}
	}
}

void Draw()
{
	ClearScreen(consoleHandle);

	for (const_iterator snakeBody = snake.begin(); snakeBody != snake.end(); ++snakeBody)
	{
		snakeBody->Draw(consoleHandle);
	}

	for (const_iterator singleFruit = fruit.begin(); singleFruit != fruit.end(); ++singleFruit)
	{
		singleFruit->Draw(consoleHandle);
	}

}

int main()
{
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
	// Randomize stuff
	srand(time(NULL));

	for (int i = SnakeStartingLength; i > -1; --i)
	{
		snake.push_back(GameObject(i, 0, SnakeSymbol));
	}

	int x = rand() % WindowWidth;
	int y = rand() % WindowHeight;
	fruit.push_back(GameObject(x, y, FruitSymbol));

	while (true)
	{
		Update();
		Draw();
		Sleep(sleepDuration);
	}

	return 0;
}