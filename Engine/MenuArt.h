#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "Stars.h"
#include "Colors.h"

class MenuArt
{
public:
	MenuArt();
	//menu background
	void Theemperor(int x, int y, Graphics& gfx);
	void Vader(int x, int y, Graphics& gfx);
	void EmperorGuard(int x, int y, Graphics& gfx);
	void GuardSaber(int x, int y, Graphics& gfx);
	//bakcground structure
	void Midline(Graphics& gfx);
	void Throne(Graphics& gfx);
	void Thestars(Graphics& gfx);
	void Window(Graphics& gfx);
	void Projector(int x, int y, Graphics& gfx);
	void Projection(int x, int y, Graphics& gfx);
	void SaberColorChange();
	void ProjectionColorChange();

	//selection menu images
	void MenuSelection(Vei2& pos, Graphics& gfx);
	void GreenSaber(Vei2& pos, Graphics& gfx);




private:
	static constexpr int maxRegularStars = 20;
	Stars Regularstars[maxRegularStars] = {};
	static constexpr int maxBrightStars = 15;
	Stars Brightstars[maxBrightStars] = {};
	int BrightStarresetMax = 100;
	int BrightStarCounter = 0;
	static constexpr int height = 4;
	static constexpr int ChairH = 50;
	Color c = Colors::White;
	Color PColor = {127,127,127};
	Color R = { 127,0,0 };
	int BR = 255;
	int DR = 128;
	bool colorIncreasing = true;
	int ColorCounter = 0;
	int ColorReset = 100;
	Vei2 Pos;
	Stars star;
};

