#include <SFML/Graphics.hpp>
#include "GlobalManager.h"
using namespace sf;
using namespace std;
#pragma once

class TextBox {
public:
	TextBox(string name, Vector2f position, Vector2f size, String BGText, String standartText, bool isEditor);

	static void SetText(string name, string text, bool isEditor);
	static string GetText(string name, bool isEditor);

	static void SetBGText(string name, string text, bool isEditor);
	static string GetBGText(string name, bool isEditor);

	static void DeleteLastSymbol(string name, bool isEditor);

	static string GetNameCurrentTextBoxSelect(bool isEditor);

	static void TextBoxUpdate(string name, Vector2f mousePosition, bool isEditor); 
};
