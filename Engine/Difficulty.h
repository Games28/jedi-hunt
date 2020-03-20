#pragma once
#include "Keyboard.h"
#include "Vei2.h"
#include "Graphics.h"

class Difficulty
{
private:
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
	void settingselection(Keyboard& kbd);
private:
	Setting settings = Setting::DEFUALT;

};

