#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
using namespace sf;
using namespace std;
#pragma once

class GlobalManager {
public:
	static void AddSquare(string name, RectangleShape object, bool isEditor);
	static void AddButton(string name, RectangleShape shape, Text text, Font font, bool isEditor);
	static void AddTextBox(string name, RectangleShape shape, Text BGText, Text standartText, Font font, bool isEditor);
	//static void AddObject(string name, Button object, bool isEditor);

	static RectangleShape GetSquare(int i, bool isEditor);
	static RectangleShape GetSquare(string name, bool isEditor);
	static RectangleShape GetButtonShape(int i, bool isEditor);
	static RectangleShape GetButtonShape(string name, bool isEditor);
	static RectangleShape GetTextBoxShape(int i, bool isEditor);
	static RectangleShape GetTextBoxShape(string name, bool isEditor);
	static string currentSquareClick(Vector2f mousePosition);
	static string currentSquareClickEditor(Vector2f mousePosition);
	static Font GetFontTextTextBox(string name, bool isEditor);
	static void SetTextTextBox(string name, Text edit_text, bool isEditor);
	static void SetBGTextTextBox(string name, Text edit_text, bool isEditor);
	static void SetSelectTextBox(string name, bool select, bool isEditor);
	static bool GetSelectTextBox(string name, bool isEditor);
	static String GetOriginalBGText(string name, bool isEditor);
	static bool isClickSquare(string name, Vector2f mousePosition, bool isEditor);
	static string GetNameTextBox(int i, bool isEditor);
	static int GetTextBoxesLength(bool isEditor);
	static Text GetBGTextBox(int i, bool isEditor);
	static Text GetBGTextBox(string name, bool isEditor);
	static Text GetTextBox(int i, bool isEditor);
	static Text GetTextBox(string name, bool isEditor);
	static Text GetButtonText(int i, bool isEditor);
	static int GetSquareCount(bool isEditor);
	static int GetButtonCount(bool isEditor);
	static int GetTextBoxCount(bool isEditor);

	static void AllButtonsUpdate(Vector2f mousePosition, bool isEditor);
	static void AllTextBoxUpdate(Vector2f mousePosition, bool isEditor);

	static void SetPosition(string name, Vector2f position, bool isEditor);
	static void SetRotate(string name, int angle, bool isEditor);
	static void SetSize(string name, Vector2f size, bool isEditor);
	static void SetColor(string name, Color color, bool isEditor);

	static void Move(string name, Vector2f offset, bool isEditor);
	static void Rotate(string name, int angle, bool isEditor);
	static void Scale(string name, Vector2f offset, bool isEditor);
};
