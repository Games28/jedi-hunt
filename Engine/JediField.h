#pragma once
#include "Vei2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "RectI.h"
//#include "MenuOptions.h"
#include <assert.h>
#include <random>
#include <algorithm>
#include "Characters.h"
#include "Keyboard.h"
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
		void Draw(const Vei2& pos,JediField::State stage,Characters::characterOptions COptions , Graphics& gfx) const;
		bool NotDroidLookingFor() const;
		void DroidScanresults(int scancount);
		
	private:
		State state = State::HIDDEN;
		Characters::characterOptions CharOpts = Characters::characterOptions::DEFAULT;
		Characters jedichar;
		bool hasjedi = false;
		int DroidSensorNumber = -1;
	};
public:
	void Draw(Graphics& gfx) const;
	RectI GetRect() const;
	JediField(const Vei2 center, int width, int height, int nJedi);
	void keySelection(Keyboard& kbd);
	void DrawSaber(Graphics& gfx);
	void OnRevealClick(const Vei2& screenPos);
	void OnProbeClick(const Vei2& screenPos);
	void reset();
	void freeResources();
	State GetState() const;
private:
	void Reveallocation(const Vei2& gridpos);
	Tile& TileAt(const Vei2& gridpos);
	Vei2 ScreenToGrid(const Vei2& ScreenPos);
	const Tile& TileAt(const Vei2 gridpos) const;
	int DroidScanCount(const Vei2& gridpos);
	bool JediFound() const;
private:
	//bool IsDetected = false; 
	 int width = 10;
	int height = 8;
	static constexpr int borderThickness = 10;
	static constexpr Color borderColor = Colors::Blue;
	Characters::characterOptions CharacterOpt = Characters::characterOptions::DEFAULT;
	Characters character;
	Vei2 topLeft;
	State jstate = State::Probing;
	Tile* Jfield = nullptr;
	
};

