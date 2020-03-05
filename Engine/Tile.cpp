#include "Tile.h"
#include <assert.h>

#undef min
#undef max

bool Tile::HasJedi() const
{
	return hasjedi;
}

void Tile::SpawnJedi()
{
	assert(!hasjedi);
	hasjedi = true;
}

bool Tile::isRevealed() const
{
	return state == State::REVEALED;
}

void Tile::Reveal()
{
	assert(state == State::HIDDEN);
	state = State::REVEALED;
}

bool Tile::hasProbe() const
{

	return state == State::PROBE;
}

void Tile::Probed()
{
	assert(!isRevealed());
	if (state == State::HIDDEN)
	{
		state = State::PROBE;
	}
	else
	{
		state = State::HIDDEN;
	}
}

void Tile::Draw(const Vei2& pos, State stage, Graphics& gfx)
{
	if (stage != State::IsDetected)
	{
		switch (state)
		{
		case State::HIDDEN:
			SpriteCodex::DrawTileTerminalButton(pos, gfx);
			break;
		case State::REVEALED:
			if (!hasjedi)
			{
				SpriteCodex::DrawTileNumber(pos, DroidSensorNumber, gfx);
			}
			else
			{
				Jmenu.DrawCharacters(pos, gfx);

			}
			break;
		case State::PROBE:
			SpriteCodex::DrawProbedroid(pos, gfx);
			break;
		}
	}
	else
	{
		switch (state)
		{
		case State::HIDDEN:
			if (hasjedi)
			{
				Jmenu.DrawCharacters(pos, gfx);
			}
			else {
				SpriteCodex::DrawTileTerminalButton(pos, gfx);
			}
			break;
		case State::REVEALED:
			if (!hasjedi)
			{
				SpriteCodex::DrawTileNumber(pos, DroidSensorNumber, gfx);


			}
			else {
				SpriteCodex::DrawProbedroidRed(pos, gfx);
			}
			break;
		case State::PROBE:
			if (hasjedi)
			{
				//SpriteCodex::DrawR2d2(pos, gfx);
				SpriteCodex::DrawProbedroid(pos, gfx);

			}
			else {
				Jmenu.DrawAlertCharacters(pos, gfx);
			}
			break;
		}

	}
}

void Tile::DroidScanresults(int scancount)
{
	assert(DroidSensorNumber == -1);
	DroidSensorNumber = scancount;
}
