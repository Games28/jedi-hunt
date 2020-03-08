#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "Vei2.h"
class ArtBackground
{
public:
	ArtBackground() = default;
	void MenuSelection(Vei2& pos, Graphics& gfx);
	void GreenSaber(Vei2& pos, Graphics& gfx);
	
	void Theemperor(int x, int y,Graphics& gfx);
	void Vader(int x, int y,Graphics& gfx);
	void EmperorGuard(int x, int y, Graphics& gfx);
	void GuardSaber(int x, int y, Graphics& gfx, Color R);
	void EmperorDoIt(int x, int y, Graphics& gfx);
	void EmperorHand(int x, int y, Graphics& gfx);

	
};

