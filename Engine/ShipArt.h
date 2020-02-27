#pragma once
#include "Graphics.h"
#include "Vei2.h"
class ShipArt
{
public:
	 void LeiaHidout(Vei2& pos, Graphics& gfx);
	 void LightsOn(Vei2& pos, Graphics& gfx);
	 void LightsOff(Vei2& pos, Graphics& gfx);
	 void LightsAnimation(Vei2& pos, Graphics& gfx);
private:
	static constexpr int LightCounterMax = 500;
	int lightCounter = 0;
};

