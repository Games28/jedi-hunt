#pragma once
#include "TheMenu.h"
#include <assert.h>
class JediField;

class Tile
{
public:
	
public:
		enum class Stage
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
		void Draw(const Vei2& pos, JediField::State stage, Graphics& gfx);
		void DroidScanresults(int scancount);
		TheMenu Jmenu;
	private:
		Stage state = Stage::HIDDEN;

		bool hasjedi = false;
		int DroidSensorNumber = -1;
	}
};

