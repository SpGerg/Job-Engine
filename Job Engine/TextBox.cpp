#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GlobalListener.h"
#include "GlobalManager.h"
#include "TextBox.h"
using namespace sf;
using namespace std;

TextBox::TextBox(string name, Vector2f position, Vector2f size, String BGText, String standartText, bool isEditor) {
	Vector2f textCenterPosition = Vector2f(size.x / 2, size.y / 2);
	RectangleShape rect;
	rect.setPosition(position);
	rect.setSize(size);

	Font font;
	font.loadFromFile("C:/Users/fokus/Desktop/JobEngine/Release/assets/fonts/arial.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString(standartText);
	text.setPosition(Vector2f(position.x, position.y));
	text.setFillColor(Color::Black);

	Text _BGText;
	_BGText.setFont(font);
	_BGText.setCharacterSize(30);
	_BGText.setString(BGText);
	_BGText.setPosition(Vector2f(position.x, position.y));
	_BGText.setFillColor(Color(230, 230, 230));

	GlobalManager::AddTextBox(name, rect, _BGText, text, font, isEditor);
}

void TextBox::SetText(string name, string text, bool isEditor) {
	Text res;
	res.setFont(GlobalManager::GetFontTextTextBox(name, isEditor));
	res = GlobalManager::GetTextBox(name, isEditor);
	res.setString(text);

	GlobalManager::SetTextTextBox(name, res, isEditor);
}

string TextBox::GetText(string name, bool isEditor) {
	return GlobalManager::GetTextBox(name, isEditor).getString().toAnsiString();
}

void TextBox::SetBGText(string name, string text, bool isEditor) {
	Text res;
	res.setFont(GlobalManager::GetFontTextTextBox(name, isEditor));
	res = GlobalManager::GetBGTextBox(name, isEditor);
	res.setString(text);
	GlobalManager::SetBGTextTextBox(name, res, isEditor);
}

string TextBox::GetBGText(string name, bool isEditor) {
	return GlobalManager::GetBGTextBox(name, isEditor).getString().toAnsiString();
}

void TextBox::DeleteLastSymbol(string name, bool isEditor) {
	string str = GetText(name, isEditor);
	if (str.size() >= 1) {
		str.erase(str.rbegin().base() - 1);
	}

	SetText(name, str, isEditor);
}

string TextBox::GetNameCurrentTextBoxSelect(bool isEditor) {
	for (int i = 0;i < GlobalManager::GetTextBoxesLength(isEditor);i++) {
		if (GlobalManager::GetSelectTextBox(GlobalManager::GetNameTextBox(i, isEditor), isEditor)) {
			return GlobalManager::GetNameTextBox(i, isEditor);
		}
	}

	return "";
}

void TextBox::TextBoxUpdate(string name, Vector2f mousePosition, bool isEditor) {
	if (GlobalManager::GetTextBoxShape(name, isEditor).getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			GlobalManager::SetSelectTextBox(name, true, isEditor);
			SetBGText(name, "", isEditor);		
		}
	}
	if (GlobalManager::GetSelectTextBox(name, isEditor)) {
		if (Listener::currentKeyPressed != "") {
			SetText(name, GetText(name, isEditor) + Listener::currentKeyPressed, isEditor);
		}
	}
	if(!GlobalManager::GetTextBoxShape(name, isEditor).getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			GlobalManager::SetSelectTextBox(name, false, isEditor);
			if (GetText(name, isEditor).size() <= 0) {
				SetBGText(name, GlobalManager::GetOriginalBGText(name, isEditor), isEditor);
			}
		}
	}
}