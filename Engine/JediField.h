#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "RectI.h"
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
	class Tile
	{
		enum class State
		{
			HIDDEN,
			REVEALED,
			PROBE
		};
	public:
		bool HasJedi() const;
		void SpawnJedi();
		bool isRevealed() const;
		void Reveal();
		bool hasProbe() const;
		void Probed();
		void Draw(const Vei2& pos,JediField::State stage, Graphics& gfx) const;
		void DroidScanresults(int scancount);
	private:
		State state = State::HIDDEN;
		bool hasjedi = false;
		int DroidSensorNumber = -1;
	};
public:
	void Draw(Graphics& gfx) const;
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

