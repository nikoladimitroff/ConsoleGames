#ifndef CONSOLE_GAMING_GUARD
#define CONSOLE_GAMING_GUARD

#include <iostream>
#include <Windows.h>

class GameObject
{
public: 
	COORD Coordinates;
	char Symbol;

	GameObject::GameObject(COORD coordinates, char symbol)
	{
		this->Coordinates = coordinates;
		this->Symbol = symbol;
	}

	GameObject::GameObject(int x, int y, char symbol)
	{
		COORD coordinates = { x, y };
		this->Coordinates = coordinates;
		this->Symbol = symbol;
	}

	GameObject::GameObject(const GameObject& gameObject)
	{
		COORD coordinates = { gameObject.Coordinates.X, gameObject.Coordinates.Y };
		this->Coordinates = coordinates;
		this->Symbol = gameObject.Symbol;
	}

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