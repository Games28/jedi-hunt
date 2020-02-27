#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "Stars.h"
#include <random>
class CoruscantArt
{
public:
	CoruscantArt();
	void JediTemple(Vei2& pos, Graphics& gfx);
	void StarAnimation(Graphics& gfx);
private:
	static constexpr int maxRegularStars = 50;
	Stars Regularstars[maxRegularStars];
	static constexpr int maxBrightStars = 50;
	Stars Brightstars[maxBrightStars];
	int BrightStarresetMax = 100;
	int BrightStarCounter = 0;
};

