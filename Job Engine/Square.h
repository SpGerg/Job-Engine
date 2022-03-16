#include <SFML/Graphics.hpp>
#include "GlobalManager.h"
using namespace sf;
using namespace std;
#pragma once

class Square {
public:
	Square(string name, Vector2f position, Vector2f size, int angle, Color color, bool isEditor);
};