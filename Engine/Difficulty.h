#pragma once
#include "Keyboard.h"
#include "Vei2.h"
#include "Graphics.h"

class Difficulty
{
public:
	enum class Setting
	{
		EASY,
		MEDIUM,
		HARD,
		DEFUALT
	};

public:
	Difficulty() = default;
	void PurpleSaber(const Vei2& pos, Graphics& gfx);
	void selection(Keyboard& kbd);
	void TheSetting();
	Vei2 widthandheight();
	int Amount();
	void Draw(Graphics& gfx);
	Setting& getSetting();
private:
	Setting settings = Setting::DEFUALT;
	Vei2 WH;
	int amount;
};

