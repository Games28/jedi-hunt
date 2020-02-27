#pragma once
#include "Graphics.h"
#include "Vei2.h"
class TatooineArt
{
public:
	void ObiwanHut(Vei2& pos, Graphics& gfx);
	void BigSun1(Vei2& pos, Graphics& gfx);
	void BigSun2(Vei2& pos, Graphics& gfx);
	void SmallSun1(Vei2& pos, Graphics& gfx);
	void SmallSun2(Vei2& pos, Graphics& gfx);
	void SunAnimation(Vei2& pos, Graphics& gfx);
private:
	static constexpr int sunCounterMax= 200;
	int SunCounter = 0;
};

