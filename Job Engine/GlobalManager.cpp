#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
#include "GlobalManager.h"
#include "TextBox.h"
using namespace sf;
using namespace std;

vector<string> namesRectangles;
vector<RectangleShape> RectangleShapes;

vector<string> namesButtons;
vector<RectangleShape> buttonsShapes;
vector<Text> buttonsTexts;
vector<Font> buttonsFonts;

vector<string> namesTextBoxes;
vector<RectangleShape> shapesTextBox;
vector<Text> BGTextsBoxesTexts;
vector<Text> textsBoxesTexts;
vector<Font> textsBoxesFonts;
vector<bool> textBoxSelect;
vector<String> originalBGText;

vector<string> namesTextBoxesEditor;
vector<RectangleShape> shapesTextBoxEditor;
vector<Text> BGTextsBoxesTextsEditor;
vector<Text> textsBoxesTextsEditor;
vector<Font> textsBoxesFontsEditor;
vector<bool> textBoxSelectEditor;
vector<String> originalBGTextEditor;

vector<string> namesButtonsEditor;
vector<RectangleShape> buttonsShapesEditor;
vector<Text> buttonsTextsEditor;
vector<Font> buttonsFontsEditor;
vector<Button> buttonsClassEditor;

vector<string> namesRectanglesEditor;
vector<RectangleShape> RectangleShapesEditor;

void GlobalManager::AddSquare(string name, RectangleShape object, bool isEditor) { // I hope to improve this code later :/
	if (!isEditor) { 
		if (find(namesRectangles.begin(), namesRectangles.end(), name) == namesRectangles.end() || find(namesButtons.begin(), namesButtons.end(), name) == namesButtons.end()) {
			namesRectangles.push_back(name);
			RectangleShapes.push_back(object);
		}	
		else {
			cout << "You cant create object name with " << name << endl;
		}
	}
	else {
		namesRectanglesEditor.push_back(name);
		RectangleShapesEditor.push_back(object);
	}	
}

void GlobalManager::AddButton(string name, RectangleShape shape, Text text, Font font, bool isEditor) {
	if (!isEditor) {	
		namesButtons.push_back(name);
		buttonsShapes.push_back(shape);
		buttonsTexts.push_back(text);
		buttonsFonts.push_back(font);
	}
	else {
		namesButtonsEditor.push_back(name);
		buttonsShapesEditor.push_back(shape);
		buttonsTextsEditor.push_back(text);
		buttonsFontsEditor.push_back(font);
	}
}

void GlobalManager::AddTextBox(string name, RectangleShape shape, Text BGText, Text standartText, Font font, bool isEditor) {
	if (!isEditor) {
		namesTextBoxes.push_back(name);
		shapesTextBox.push_back(shape);
		textsBoxesTexts.push_back(standartText);
		BGTextsBoxesTexts.push_back(BGText);
		textsBoxesFonts.push_back(font);
		originalBGText.push_back(BGText.getString());
		textBoxSelect.push_back(false);
	}
	else {
		namesTextBoxesEditor.push_back(name);
		shapesTextBoxEditor.push_back(shape);
		textsBoxesTextsEditor.push_back(standartText);
		BGTextsBoxesTextsEditor.push_back(BGText);
		textsBoxesFontsEditor.push_back(font);
		originalBGTextEditor.push_back(BGText.getString());
		textBoxSelectEditor.push_back(false);
	}
}

/*
void GlobalManager::AddObject(string name, Button object, bool isEditor) {
	if (!isEditor) {
		if (find(namesButtons.begin(), namesButtons.end(), name) == namesButtons.end()) {
			namesButtons.push_back(name);
			Buttons.push_back(object);
		}
		else {
			cout << "You cant create object name with " << name << endl;
		}
	}
	else {
		if (find(namesButtonsEditor.begin(), namesButtonsEditor.end(), name) == namesButtonsEditor.end()) {
			namesButtonsEditor.push_back(name);
			ButtonsEditor.push_back(object);
		}
		else {
			cout << "You cant create object name with " << name << endl;
		}
	}
}
*/
void GlobalManager::SetPosition(string name, Vector2f position, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).setPosition(position);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).setPosition(position);
			}
		}
	}
}

void GlobalManager::AllButtonsUpdate(Vector2f mousePosition, bool isEditor) {
	for (int i = 0;i < namesButtons.size();i++) {
		Button::ButtonUpdate(namesButtons.at(i), mousePosition, isEditor);
	}
	for (int i = 0;i < namesButtonsEditor.size();i++) {
		Button::ButtonUpdate(namesButtonsEditor.at(i), mousePosition, isEditor);
	}
}

void GlobalManager::SetSize(string name, Vector2f size, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).setSize(size);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).setSize(size);
			}
		}
	}
}

void GlobalManager::SetRotate(string name, int angle, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).setRotation(angle);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).setRotation(angle);
			}
		}
	}
}

void GlobalManager::SetColor(string name, Color color, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).setFillColor(color);
			}			
		}
		for (int i = 0;i < namesButtons.size();i++) {
			if (namesButtons.at(i) == name) {
				buttonsShapes.at(i).setFillColor(color);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).setFillColor(color);
			}
		}
		for (int i = 0;i < namesButtonsEditor.size();i++) {
			if (namesButtonsEditor.at(i) == name) {
				buttonsShapesEditor.at(i).setFillColor(color);
			}
		}
	}
}

void GlobalManager::Move(string name, Vector2f offset, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).move(offset);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).move(offset);
			}
		}
	}
}

void GlobalManager::Scale(string name, Vector2f offset, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).scale(offset);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).scale(offset);
			}
		}
	}
}

void GlobalManager::Rotate(string name, int angle, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				RectangleShapes.at(i).rotate(angle);
			}
		}
	}
	else {
		for (int i = 0;i < namesRectanglesEditor.size();i++) {
			if (namesRectanglesEditor.at(i) == name) {
				RectangleShapesEditor.at(i).rotate(angle);
			}
		}
	}
}

RectangleShape GlobalManager::GetTextBoxShape(int i, bool isEditor) {
	if (!isEditor) {
		return shapesTextBox.at(i);
	}

	return shapesTextBoxEditor.at(i);
}

RectangleShape GlobalManager::GetTextBoxShape(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesTextBoxes.size();i++) {
			if (name == namesTextBoxes.at(i)) {
				return shapesTextBox.at(i);
				break;
			}
		}
	}
	
	for (int i = 0;i < namesTextBoxesEditor.size();i++) {
		if (name == namesTextBoxesEditor.at(i)) {
			return shapesTextBoxEditor.at(i);
			break;
		}
	}
}

Text GlobalManager::GetBGTextBox(int i, bool isEditor) {
	if (!isEditor) {
		Text text;
		text = BGTextsBoxesTexts.at(i);
		text.setFont(textsBoxesFonts.at(i));
		return text;
	}

	Text text;
	text = BGTextsBoxesTextsEditor.at(i);
	text.setFont(textsBoxesFontsEditor.at(i));
	return text;
}

Text GlobalManager::GetTextBox(int i, bool isEditor) {
	if (!isEditor) {
		Text text;
		text = textsBoxesTexts.at(i);
		text.setFont(textsBoxesFonts.at(i));
		return text;
	}

	Text text;
	text = textsBoxesTextsEditor.at(i);
	text.setFont(textsBoxesFontsEditor.at(i));
	return text;
}

RectangleShape GlobalManager::GetButtonShape(int i, bool isEditor) {
	if (!isEditor) {
		return buttonsShapes.at(i);
	}

	return buttonsShapesEditor.at(i);
}

Text GlobalManager::GetButtonText(int i, bool isEditor) {
	if (!isEditor) {
		Text text;
		text = buttonsTexts.at(i);
		text.setFont(buttonsFonts.at(i));

		return text;
	}

	Text text;
	text = buttonsTextsEditor.at(i);
	text.setFont(buttonsFontsEditor.at(i));

	return text;
}

RectangleShape GlobalManager::GetSquare(int i, bool isEditor) {
	if (!isEditor) {
		return RectangleShapes.at(i);
	}

	return RectangleShapesEditor.at(i);
}

Text GlobalManager::GetTextBox(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < shapesTextBox.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				return textsBoxesTexts.at(i);
				break;
			}
		}
	}
	
	for (int i = 0;i < shapesTextBoxEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			return textsBoxesTextsEditor.at(i);
			break;
		}
	}
}

Text GlobalManager::GetBGTextBox(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < shapesTextBox.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				return BGTextsBoxesTexts.at(i);
				break;
			}
		}
	}

	for (int i = 0;i < shapesTextBoxEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			return BGTextsBoxesTextsEditor.at(i);
			break;
		}
	}
}

String GlobalManager::GetOriginalBGText(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesTextBoxes.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				return originalBGText.at(i);
			}
		}
	}

	for (int i = 0;i < namesTextBoxesEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			return originalBGTextEditor.at(i);
		}
	}
}

bool GlobalManager::isClickSquare(string name, Vector2f mousePosition, bool isEditor) {
	if (GlobalManager::GetSquare(name, isEditor).getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y))) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

RectangleShape GlobalManager::GetSquare(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesRectangles.size();i++) {
			if (namesRectangles.at(i) == name) {
				return RectangleShapes.at(i);
			}
		}

		RectangleShape rect;
		return rect;
	}

	for (int i = 0;i < namesRectanglesEditor.size();i++) {
		if (namesRectanglesEditor.at(i) == name) {
			return RectangleShapesEditor.at(i);
		}
	}

	RectangleShape rect;
	return rect;
}

void GlobalManager::SetTextTextBox(string name, Text edit_text, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < shapesTextBox.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				textsBoxesTexts.at(i) = edit_text;
				return;
				break;
			}
		}
	}

	for (int i = 0;i < shapesTextBoxEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			textsBoxesTextsEditor.at(i) = edit_text;
			return;
			break;
		}
	}
}

void GlobalManager::SetSelectTextBox(string name, bool select, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesTextBoxes.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				textBoxSelect.at(i) = select;
				break;
				return;
			}
		}
	}

	for (int i = 0;i < namesTextBoxesEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			textBoxSelectEditor.at(i) = select;
			break;
			return;
		}
	}
}

string GlobalManager::currentSquareClick(Vector2f mousePosition) {	
	for (int i = 0;i < namesRectangles.size();i++) {
		if (GetSquare(i, false).getGlobalBounds().contains(mousePosition)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				return namesRectangles.at(i);
			}
		}
	}
	

	return "";
}

string GlobalManager::currentSquareClickEditor(Vector2f mousePosition) {
	for (int i = 0;i < namesRectanglesEditor.size();i++) {
		if (GetSquare(i, true).getGlobalBounds().contains(mousePosition)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				return namesRectanglesEditor.at(i);
			}
		}
	}


	return "";
}

bool GlobalManager::GetSelectTextBox(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesTextBoxes.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				return textBoxSelect.at(i);
				break;
			}
		}
	}

	for (int i = 0;i < namesTextBoxesEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			return textBoxSelectEditor.at(i);
			break;
		}
	}
}

void GlobalManager::SetBGTextTextBox(string name, Text edit_text, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < shapesTextBox.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				BGTextsBoxesTexts.at(i) = edit_text;
				return;
				break;
			}
		}
	}

	for (int i = 0;i < shapesTextBoxEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			BGTextsBoxesTextsEditor.at(i) = edit_text;
			return;
			break;
		}
	}
}

Font GlobalManager::GetFontTextTextBox(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < shapesTextBox.size();i++) {
			if (namesTextBoxes.at(i) == name) {
				return textsBoxesFonts.at(i);
				break;
			}
		}
	}

	for (int i = 0;i < shapesTextBoxEditor.size();i++) {
		if (namesTextBoxesEditor.at(i) == name) {
			return textsBoxesFontsEditor.at(i);
			break;
		}
	}
}

int GlobalManager::GetSquareCount(bool isEditor) {
	if (!isEditor) {
		return RectangleShapes.size();
	}

	return RectangleShapesEditor.size();
}

string GlobalManager::GetNameTextBox(int i, bool isEditor) {
	if (!isEditor) {
		return namesTextBoxes.at(i);
	}

	return namesTextBoxesEditor.at(i);
}

int GlobalManager::GetTextBoxesLength(bool isEditor) {
	if (!isEditor) {
		return namesTextBoxes.size();
	}

	return namesTextBoxesEditor.size();
}

int GlobalManager::GetTextBoxCount(bool isEditor) {
	if (!isEditor) {
		return shapesTextBox.size();
	}

	return shapesTextBoxEditor.size();
}

int GlobalManager::GetButtonCount(bool isEditor) {
	if (!isEditor) {
		return buttonsShapes.size();
	}

	return buttonsShapesEditor.size();
}

RectangleShape GlobalManager::GetButtonShape(string name, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesButtons.size();i++) {
			if (namesButtons.at(i) == name) {
				return buttonsShapes.at(i);
				break;
			}
		}
	}
	else {
		for (int i = 0;i < namesButtonsEditor.size();i++) {
			if (namesButtonsEditor.at(i) == name) {
				return buttonsShapesEditor.at(i);
				break;
			}
		}
	}

	RectangleShape rect;
	return rect;
}

void GlobalManager::AllTextBoxUpdate(Vector2f mousePosition, bool isEditor) {
	if (!isEditor) {
		for (int i = 0;i < namesTextBoxes.size();i++) {
			TextBox::TextBoxUpdate(namesTextBoxes.at(i), mousePosition, isEditor);
		}
	}
}

