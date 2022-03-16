#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GlobalManager.h"
#include "Square.h"
using namespace sf;
using namespace std;

Square::Square(string name, Vector2f position, Vector2f size, int angle, Color color, bool isEditor) {
	RectangleShape rect;
	rect.setPosition(position);
	rect.setSize(size);
	rect.setFillColor(color);
	rect.setRotation(angle);
	GlobalManager::AddSquare(name, rect, isEditor);
}