#pragma once
#include "Colors.h"
class Graphics;
class ArtBackground
{
public:
	ArtBackground() = default;
	
	void Theemperor(int x, int y,Graphics& gfx);
	void Vader(int x, int y,Graphics& gfx);
	void EmperorGuard(int x, int y, Graphics& gfx);
	void GuardSaber(int x, int y, Graphics& gfx, Color R);
	void EmperorDoIt(int x, int y, Graphics& gfx);
	void EmperorHand(int x, int y, Graphics& gfx);

	
};

