#pragma once
#include "Graphics.h"
#include "Vei2.h"
class DagobahArt
{
public:
	 void YodaHut(Vei2& pos, Graphics& gfx);
	 void Waves1(Vei2& pos, Graphics& gfx);
	 void Waves2(Vei2& pos, Graphics& gfx);
	 void WaveAnimation(Vei2& pos, Graphics& gfx);
private:
	static constexpr int waveCountMax = 200;
	int waveCounter = 0;
};

