#include <SFML/Graphics.hpp>
#include "Button.h"
#include "main.h"
#include <iostream>
#include "GlobalManager.h"
using namespace sf;
using namespace std;

Text CreateText(string text, Font font, int fontSize, Vector2f position, Vector2f size) {
	Vector2f textCenterPosition = Vector2f(size.x / 2, size.y / 2);
	Text _text;
	_text.setFont(font);
	_text.setString(text);
	_text.setCharacterSize(fontSize);
	_text.setPosition(Vector2f(textCenterPosition.x - _text.getGlobalBounds().width / 2 + position.x,
		textCenterPosition.y - _text.getGlobalBounds().height / 2 + position.y - 5));
	_text.setFillColor(Color::Black);
	return _text;
}

Button::Button(string name, Vector2f position, Vector2f size, int fontSize, string text, bool isEditor) {
	Font font;
	font.loadFromFile("C:/Users/fokus/Desktop/JobEngine/Release/assets/fonts/arial.ttf");
	Text _text = CreateText(text, font, fontSize, position, size);
	RectangleShape rect;
	rect.setPosition(position);
	rect.setSize(size);

	GlobalManager::AddButton(name, rect, _text, font, isEditor);
}

bool Button::isCollision(string name, Vector2f mousePosition, bool isEditor) {
	if (GlobalManager::GetButtonShape(name, isEditor).getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y))) {
		GlobalManager::SetColor(name, Color(220, 220, 220), isEditor);
		return true;
	}
	else {
		GlobalManager::SetColor(name, Color::White, isEditor);
		return false;
	}

	return false;
}


bool Button::isClick(string name, Vector2f mousePosition, bool isEditor) {
	if (GlobalManager::GetButtonShape(name, isEditor).getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y))) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			GlobalManager::SetColor(name, Color(190, 190, 190), isEditor);
			return true;
		}
		else {
			isCollision(name, mousePosition, isEditor);
			return false;
		}
	}
	else {
		GlobalManager::SetColor(name, Color::White, isEditor);
		return false;
	}

	return false;
}

void Button::ButtonUpdate(string name, Vector2f mousePosition, bool isEditor) {
	isCollision(name, mousePosition, isEditor);
	isClick(name, mousePosition, isEditor);
}