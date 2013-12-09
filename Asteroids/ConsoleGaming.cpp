#include "ConsoleGaming.h"

ConsoleColor GameObject::BackgroundColor = 0x00;

void ClearScreen(HANDLE consoleHandle)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	if (consoleHandle == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( consoleHandle, &csbi )) 
		return;

	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
			consoleHandle,
			(TCHAR) ' ',
			cellCount,
			homeCoords,
			&count)) 
		return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
			consoleHandle,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count)) 
		return;

	/* Move the cursor home */
	SetConsoleCursorPosition(consoleHandle, homeCoords);
}