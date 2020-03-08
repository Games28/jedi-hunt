#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "Stars.h"
#include "ArtBackground.h"
#include "Colors.h"
#include "RectI.h"
#include "Keyboard.h"
#include "MenuOptions.h"
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
	
public:
	TheMenu();
	TheMenu(Vei2& pos);
	void BlueSaber(Vei2& pos, Graphics& gfx);
	void GreenSaber(Vei2& pos, Graphics& gfx);
	void PurpleSaber(Vei2& pos, Graphics& gfx);
	
	 void MenuSelection(Vei2& pos, Graphics& gfx);
	
public:
	
	///void ButtonSelect( Keyboard& kbd);//iskeypress function
	void Draw(Graphics& gfx);// draw base on iskeypress
	static constexpr Color C = Colors::Gray;

private:

	Vei2 topLeft{ 204,165 };
	Vei2 offset{ 4,4 };
	int offSet = 4;
	Vei2 Pos;
	
	

	static constexpr int ButtonWidth = 88;
	static constexpr int ButtonHeight = 27;
	static constexpr int Width = 3;
	static constexpr int Height = 4;
	int Buttons[ButtonWidth * ButtonHeight];
};

