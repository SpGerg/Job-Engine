#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#pragma once

class Button {
public:
	Button(string name, Vector2f position, Vector2f size, int fontSize, string text, bool isEditor);

	static bool isClick(string name, Vector2f mousePosition, bool isEditor);
	static bool isCollision(string name, Vector2f mousePosition, bool isEditor);
	static void ButtonUpdate(string name, Vector2f mousePosition, bool isEditor);
};
