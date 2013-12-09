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
// Ball variables
int ballSpeed = 1;

// Paddle variables
const int PaddleLength = 5;
int paddleSpeed = 1;

// Game variables
unsigned long sleepDuration = 200;

vector<vector<GameObject>> paddles;
GameObject ball(WindowWidth / 2, WindowHeight / 2, '#');

void Update()
{
	COORD direction = { 0, 0 };
	if (kbhit())
	{
		char key = getch();
		switch (key)
		{
		case 'a':
			direction.Y = 0;
			break;
		case 'w':
			direction.Y = -paddleSpeed;
			break;
		case 'd':
			direction.Y = 0;
			break;
		case 's':
			direction.Y = paddleSpeed;
			break;
		};
	}
	typedef vector<vector<GameObject>>::iterator vector_iterator;
	vector_iterator playerPaddle = paddles.begin();

	for (randomAccess_iterator paddle = playerPaddle->begin(); paddle != playerPaddle->end(); ++paddle)
	{
		paddle->Coordinates.X += direction.X;
		paddle->Coordinates.Y += direction.Y;
	}

	ball.Coordinates.X += ballSpeed;
	if (ball.Coordinates.X >= WindowWidth - 1 || ball.Coordinates.X <= 0)
	{
		ballSpeed = -ballSpeed;
	}
}

void Draw()
{
	ClearScreen(consoleHandle);

	typedef vector<vector<GameObject>>::iterator vector_iterator;
	for (vector_iterator paddle = paddles.begin(); paddle != paddles.end(); ++paddle)
	{
		for (randomAccess_iterator paddlePart = paddle->begin(); paddlePart != paddle->end(); ++paddlePart)
		{
			paddlePart->Draw(consoleHandle);
		}
	}	
	ball.Draw(consoleHandle);
}

int main()
{
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );

	srand(time(NULL));

	vector<GameObject> leftPaddle, rightPaddle;
	int paddleStartingPos = WindowHeight / 2 - PaddleLength / 2;
	for (int i = 0; i < PaddleLength; ++i)
	{
		leftPaddle.push_back(GameObject(0, paddleStartingPos + i, '*'));
		rightPaddle.push_back(GameObject(WindowWidth - 1, paddleStartingPos + i, '*'));
	}
	paddles.push_back(leftPaddle);
	paddles.push_back(rightPaddle);

	while (true)
	{
		Update();
		Draw();
		Sleep(sleepDuration);
	}

	return 0;
}