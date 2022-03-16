#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Square.h"
#include "Button.h"
#include "TextBox.h"
#include "GlobalManager.h"
#include "GlobalListener.h"
#include "main.h"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Job Engine");
	Vector2f mousePosition;

	JWindow jwn;

	jwn.PanelsInit();
	jwn.ButtonsInit();
	jwn.TextBoxInit();

	while (window.isOpen())
	{
		Event event;

		mousePosition = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

		GlobalManager::AllButtonsUpdate(mousePosition, true);
		GlobalManager::AllButtonsUpdate(mousePosition, false);

		jwn.ButtonsUpdate(mousePosition);
		jwn.ObjectsUpdate(mousePosition);

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			//Window size
			if (event.type == Event::Resized) {
				float w = static_cast<float>(event.size.width);
				float h = static_cast<float>(event.size.height);
				window.setView(
					View(
						Vector2f(w / 2.0, h / 2.0),
						Vector2f(w, h)
					)
				);
			}

			if (Mouse::isButtonPressed(Mouse::Left)) {		
				for (int i = 0;i < GlobalManager::GetTextBoxesLength(true);i++) {
					TextBox::TextBoxUpdate(GlobalManager::GetNameTextBox(i, true), mousePosition, true);
				}
				//GlobalManager::AllTextBoxUpdate(mousePosition, true);
			}

			if (event.type == Event::TextEntered) {
				if (event.text.unicode > 0 & event.text.unicode != '\b') {
					char key = (char)event.text.unicode;
					String str;
					str = key;
					Listener::currentKeyPressed = str;
					TextBox::TextBoxUpdate(TextBox::GetNameCurrentTextBoxSelect(true), mousePosition, true);
				}
				if (event.text.unicode == '\b') {
					TextBox::DeleteLastSymbol(TextBox::GetNameCurrentTextBoxSelect(true), true);
				}
			}
			else {
				Listener::currentKeyPressed = "";
			}
		}
		window.clear(Color(170, 170, 170));

		for (int i = 0;i < GlobalManager::GetSquareCount(true);i++) {
			window.draw(GlobalManager::GetSquare(i, true));
		}
		for (int i = 0;i < GlobalManager::GetSquareCount(false);i++) {
			window.draw(GlobalManager::GetSquare(i, false));
		}
		for (int i = 0;i < GlobalManager::GetButtonCount(false);i++) {
			window.draw(GlobalManager::GetButtonShape(i, false));
			window.draw(GlobalManager::GetButtonText(i, false));
		}
		for (int i = 0;i < GlobalManager::GetButtonCount(true);i++) {
			window.draw(GlobalManager::GetButtonShape(i, true));
			window.draw(GlobalManager::GetButtonText(i, true));
		}
		for (int i = 0;i < GlobalManager::GetTextBoxCount(true);i++) {
			window.draw(GlobalManager::GetTextBoxShape(i, true));
			window.draw(GlobalManager::GetBGTextBox(i, true));
			window.draw(GlobalManager::GetTextBox(i, true));
		}

		window.display();
	}

	return 0;
}