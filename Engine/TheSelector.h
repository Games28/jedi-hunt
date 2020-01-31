#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class TheSelector
{
public:
	TheSelector() = default;
	void CharacterSelector1(int x, int y, Graphics& gfx);
	void CharacterSelector2(int x, int y, Graphics& gfx);
	void SaberSelector1(int x, int y, Graphics& gfx);
	void SaberSelector2(int x, int y, Graphics& gfx);
	void DrawCharacterSelect(Graphics& gfx, Keyboard& brd, bool iskeypressed);

	void DrawSaberSelect(Graphics& gfx, Keyboard& brd);
	Keyboard kbd;
};

