#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "Stars.h"
#include "ArtBackground.h"
#include "Colors.h"
#include "RectI.h"
#include "MenuSelector.h"
#include "Keyboard.h"
#include <random>
class TheMenu
{
public:
	enum class Selector
	{
		BLUE,
		GREEN,
		PURPLE
	};
public:
	enum class Difficulty
	{
		EASY,
		MEDIUM,
		HARD,
		default
	};
	enum class Characters
	{
		LEIA,
		OBIWAN,
		YODA,
		R2D2,
		default
	};
	enum class Levels
	{
		TATO,
		DAGO,
		TEMPLE,
		SHIP,
		default
	};
public:
	TheMenu();
	TheMenu(Vei2& pos);

	
	 void MenuSelection(Vei2& pos, Graphics& gfx);
	
public:
	Vei2 ScreentoGrid(const Vei2& screenpos);
	int& ButtonAt(const Vei2& Buttonpos);
	RectI GetRect(Vei2& topleft);
	void nDraw(Graphics& gfx);
	void ButtonSelect( Keyboard& kbd);//iskeypress function
	void Draw(Graphics& gfx);// draw base on iskeypress
	static constexpr Color C = Colors::Gray;

private:
Difficulty Diff = Difficulty::default;
	Characters Chars = Characters::default;
	Levels Levs = Levels::default;
	Vei2 topLeft{ 204,165 };
	Vei2 offset{ 4,4 };
	int offSet = 4;
	Vei2 Pos;
	
	MenuSelector saber;
	static constexpr int ButtonWidth = 88;
	static constexpr int ButtonHeight = 27;
	static constexpr int Width = 3;
	static constexpr int Height = 4;
	int Buttons[ButtonWidth * ButtonHeight];
};

