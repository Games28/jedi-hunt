#pragma 
class Tile;
#include "Vei2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "RectI.h"
#include "TheMenu.h"
#include <assert.h>
#include <random>

#include <algorithm>
class JediField
{
public:
	enum class State
	{
		IsDetected,
		Winner,
		Probing
	};
private:
	
public:
	void Draw(Graphics& gfx);
	RectI GetRect() const;
	JediField(const Vei2 center, int nJedi);
	void OnRevealClick(const Vei2& screenPos);
	void OnProbeClick(const Vei2& screenPos);
	State GetState() const;
	
private:
	Tile& TileAt(const Vei2& gridpos);
	Vei2 ScreenToGrid(const Vei2& ScreenPos);
	const Tile& TileAt(const Vei2 gridpos) const;
	int DroidScanCount(const Vei2& gridpos);
	bool JediFound() const;
private:
	bool IsDetected = false; 
	static constexpr int width = 4;
	static constexpr int height = 3;
	static constexpr int borderThickness = 10;
	static constexpr Color borderColor = Colors::Blue;
	Vei2 topLeft;
	
	State jstate = State::Probing;
	Tile Jfield[width * height];
	
};

