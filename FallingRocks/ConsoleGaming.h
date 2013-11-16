#ifndef CONSOLE_GAMING_GUARD
#define CONSOLE_GAMING_GUARD

#include <iostream>
#include <Windows.h>

class GameObject
{
public: 
	COORD Coordinates;
	char Symbol;

	GameObject::GameObject(COORD coordinates, char symbol) :
		Coordinates(coordinates), Symbol(symbol)
	{	}

	GameObject::GameObject(int x, int y, char symbol) :
		Symbol(symbol)
	{
		COORD coordinates = { x, y };
		this->Coordinates = coordinates;
	}

	GameObject::GameObject(const GameObject& gameObject) :
		Coordinates(gameObject.Coordinates), Symbol(gameObject.Symbol)
	{	}

	void GameObject::UpdateCoordinates(const COORD& value)
	{
		this->Coordinates.X = value.X;
		this->Coordinates.Y = value.Y;
	}

	void GameObject::Draw(HANDLE consoleInputHandle) const
	{
		SetConsoleCursorPosition(consoleInputHandle, this->Coordinates);
		std::cout << this->Symbol;
	}
};

void ClearScreen(HANDLE consoleHandle);

#endif