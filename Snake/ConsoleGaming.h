#ifndef CONSOLE_GAMING_GUARD
#define CONSOLE_GAMING_GUARD

#include <iostream>
#include <Windows.h>

typedef unsigned char ConsoleColor;

class GameObject
{
private:
	static const ConsoleColor DefaultColor = 0xF;
	static ConsoleColor BackgroundColor;
public: 
	COORD Coordinates;
	char Symbol;
	ConsoleColor Color;

	GameObject::GameObject(COORD coordinates, char symbol) :
		Coordinates(coordinates), Symbol(symbol), Color(DefaultColor)
	{	}

	GameObject::GameObject(int x, int y, char symbol) :
		Symbol(symbol), Color(DefaultColor)
	{
		COORD coordinates = { x, y };
		this->Coordinates = coordinates;
	}

	GameObject::GameObject(const GameObject& gameObject) :
		Coordinates(gameObject.Coordinates), Symbol(gameObject.Symbol), Color(DefaultColor)
	{	}

	void GameObject::UpdateCoordinates(const COORD& value)
	{
		this->Coordinates.X = value.X;
		this->Coordinates.Y = value.Y;
	}

	void GameObject::Draw(HANDLE consoleOutputHandle) const
	{
		SetConsoleCursorPosition(consoleOutputHandle, this->Coordinates);
		ConsoleColor color = (this->Color & 0x0F) | BackgroundColor;
		SetConsoleTextAttribute(consoleOutputHandle, color);
		std::cout << this->Symbol;
	}
	
	static void SetBackgroundColor(ConsoleColor backgroundColor)
	{
		BackgroundColor = (backgroundColor & 0x0F) << 4;
	}
};

void ClearScreen(HANDLE consoleHandle);


namespace ConsoleColors
{
	enum Colors
	{
		// Color space is ARGB
		Blue = 0x1,
		Green = 0x2,
		Red = 0x4,
		Yellow = Red | Green,
		Purple = Blue | Green,
		Cyan = Blue | Green,
		Black = 0,
		White = Red | Green | Blue
	};
}

#endif