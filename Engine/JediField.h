#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "RectI.h"
#include <assert.h>
#include <random>
class JediField
{
private:
	class Tile
	{
		enum State
		{
			HIDDEN,
			REVEALED,
			PROBE
		};
	public:
		bool HasJedi() const;
		void SpawnJedi();
		bool isRevealed() const;
		void Revealed();
		bool hasProbe() const;
		void LaunchedProbe();
		void Draw(const Vei2& pos, Graphics& gfx) const;
	private:
		State state = State::HIDDEN;
		bool hasjedi = false;
	};
public:
	RectI GetRect() const;
	JediField(int nJedi);
	Tile& TileAt(const Vei2& gridpos);
	const Tile& TileAt(const Vei2 gridpos) const;
	void Draw(Graphics& gfx) const;
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile Jfield[width * height];
};

