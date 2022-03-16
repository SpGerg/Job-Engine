#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Square.h"
#include "TextBox.h"
using namespace sf;
using namespace std;
#pragma once

class JWindow {
public:
	static void PanelsInit() {
		Square("upPanelOne", Vector2f(0, 0), Vector2f(3000, 100), 0, Color(140, 140, 140), true);
		Square("upPanelTwo", Vector2f(0, 100), Vector2f(3000, 80), 0, Color(160, 160, 160), true);
		Square("leftPanel", Vector2f(0, 180), Vector2f(140, 1000), 0, Color(135, 135, 135), true);
		Square("rightPanel", Vector2f(1600, 180), Vector2f(400, 1000), 0, Color(135, 135, 135), true);

		//40, 110
		Square("upArrow", Vector2f(0, 0), Vector2f(0, 0), 0, Color(255, 0, 0, 180), true);
		//110, 40
		Square("rightArrow", Vector2f(0, 0), Vector2f(0, 0), 0, Color(0, 0, 255, 180), true);
	}
	static void ButtonsInit() {
		Button("File", Vector2f(550, 110), Vector2f(100, 60), 25, "File", true);
		Button("Edit", Vector2f(750, 110), Vector2f(100, 60), 24.9f, "Edit", true);
		Button("Assets", Vector2f(950, 110), Vector2f(100, 60), 25, "Assets", true);
		Button("Info", Vector2f(1150, 110), Vector2f(100, 60), 25, "Info", true);

		Button("Scene", Vector2f(450, 0), Vector2f(100, 50), 25, "Scene", true);
		Button("Draw", Vector2f(650, 0), Vector2f(100, 50), 24.9f, "Draw", true);
		Button("Sound", Vector2f(850, 0), Vector2f(100, 50), 25, "Sound", true);
		Button("Animate", Vector2f(1050, 0), Vector2f(100, 50), 25, "Animate", true);
		Button("Code", Vector2f(1250, 0), Vector2f(100, 50), 25, "Code", true);

		Button("Square", Vector2f(8, 180), Vector2f(120, 50), 20, "Square", true);
		Button("Button", Vector2f(8, 230), Vector2f(120, 50), 21, "Button", true);
		Button("TextBox", Vector2f(8, 280), Vector2f(120, 50), 21, "TextBox", true);
	}

	static void TextBoxInit() {
		TextBox("NameBox", Vector2f(1610, 190), Vector2f(100, 50), "Name", "", true);
		TextBox("XBox", Vector2f(1610, 250), Vector2f(100, 50), "X", "", true);
		TextBox("YBox", Vector2f(1610, 310), Vector2f(100, 50), "Y", "", true);
		TextBox("AngleBox", Vector2f(1610, 370), Vector2f(100, 50), "Angle", "", true);
	}

	static void ButtonsUpdate(Vector2f mousePosition) {
		if (Button::isClick("Square", mousePosition, true) & TextBox::GetText("NameBox", true) != "") {
			Square(TextBox::GetText("NameBox", true), Vector2f(200, 200), Vector2f(200, 200), 0, Color::Red, false);
		}
		else if (Button::isClick("Square", mousePosition, true) & TextBox::GetText("NameBox", true) == "") {
			cout << "You cant create object name with: NULL";
		}

	}

	static void ObjectsUpdate(Vector2f mousePosition) {
		if (GlobalManager::currentSquareClick(mousePosition) != "") {
			GlobalManager::SetSize("upArrow", Vector2f(40, 110), true);
			GlobalManager::SetSize("rightArrow", Vector2f(110, 40), true);

			GlobalManager::SetPosition("upArrow", Vector2f(GlobalManager::GetSquare(GlobalManager::currentSquareClick(mousePosition), false).getPosition().x+80, GlobalManager::GetSquare(GlobalManager::currentSquareClick(mousePosition), false).getPosition().y-150), true);
			GlobalManager::SetPosition("rightArrow", Vector2f(GlobalManager::GetSquare(GlobalManager::currentSquareClick(mousePosition), false).getPosition().x+250, GlobalManager::GetSquare(GlobalManager::currentSquareClick(mousePosition), false).getPosition().y+80), true);

			//GlobalManager::SetPosition(GlobalManager::currentSquareClick(mousePosition),
			//	Vector2f(GlobalManager::GetSquare("upArrow", true).getPosition().x-50, GlobalManager::GetSquare("upArrow", true).getPosition().y-50),
			//	false);
		}
		else if (GlobalManager::currentSquareClick(mousePosition) == "upArrow") {
			GlobalManager::SetPosition("upArrow", Vector2f(GlobalManager::GetSquare("upArrow", true).getPosition().x, mousePosition.y), true);
		}
		else if (GlobalManager::currentSquareClick(mousePosition) == "rightArrow") {
			GlobalManager::SetPosition("rightArrow", Vector2f(mousePosition.x, GlobalManager::GetSquare("rightArrow", true).getPosition().y), true);
		}
		else if(GlobalManager::currentSquareClick(mousePosition) == "" & Mouse::isButtonPressed(Mouse::Left)) {
			GlobalManager::SetSize("upArrow", Vector2f(0, 0), true);
			GlobalManager::SetSize("rightArrow", Vector2f(0, 0), true);
		}


		GlobalManager::SetRotate(TextBox::GetText("NameBox", true), atof(TextBox::GetText("AngleBox", true).c_str()), false);
	}
};
