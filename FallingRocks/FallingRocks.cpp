#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>

#include "ConsoleGaming.h"

using namespace std;

HANDLE consoleHandle;

typedef vector<GameObject>::iterator randomAccess_iterator;
typedef vector<GameObject>::const_iterator const_iterator;

const int WindowWidth = 70;
const int WindowHeight = 30;

unsigned long sleepDuration = 200;




void Update()
{

}

void Draw()
{
	ClearScreen(consoleHandle);

}

int main()
{
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo; 
	GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

	srand(time(NULL));

	

	while (true)
	{
		Update();
		Draw();
		Sleep(sleepDuration);
	}

	return 0;
}