#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "ArtBackground.h"
#include "Colors.h"
#include "RectI.h"
#include "MenuSelector.h"
#include "Keyboard.h"
#include "Selection.h"
#include "Background.h"
#include "SpriteCodex.h"

class TheMenu
{

public:
	enum class Difficulty
	{
		EASY,
		MEDIUM,
		HARD,
		OTHER
	};
	enum class Characters
	{
		LEIA,
		OBIWAN,
		YODA,
		R2D2,
		OTHER
	};
	enum class Levels
	{
		TATO,
		DAGO,
		TEMPLE,
		SHIP,
		OTHER
	};
public:
	TheMenu();
	TheMenu(Vei2& pos);

	
	 void MenuSelection(Vei2& pos, Graphics& gfx);
	
public:
	
	void ButtonSelect( Keyboard& kbd);//iskeypress function
	void Draw(Graphics& gfx);// draw base on iskeypress
	void Drawbackground(Graphics& gfx);
	void DrawCharacters(const Vei2& pos, Graphics& gfx);
	void DrawAlertCharacters(const Vei2& pos, Graphics& gfx);
	static constexpr Color C = Colors::Gray;

public:
	
	Levels level = Levels::OTHER;
	Characters character = Characters::OTHER;
	Difficulty difficulty = Difficulty::OTHER;
 
private:
	Vei2 topLeft{ 204,165 };
	Vei2 offset{ 4,4 };
	int offSet = 4;
	Vei2 Pos;
	Background back;
	MenuSelector saber;
	SpriteCodex Chars;
	static constexpr int ButtonWidth = 88;
	static constexpr int ButtonHeight = 27;
	static constexpr int Width = 3;
	static constexpr int Height = 4;
	int Buttons[ButtonWidth * ButtonHeight];
};

