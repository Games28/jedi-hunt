#pragma once
#include "TheMenu.h"

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
		void Draw(const Vei2& pos, JediField::State stage, Graphics& gfx);
		void DroidScanresults(int scancount);
		TheMenu Jmenu;
	private:
		State state = State::HIDDEN;

		bool hasjedi = false;
		int DroidSensorNumber = -1;
	}
};

