#include "Tile.h"
#include "JediField.h"

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
	return state == Stage::REVEALED;
}

void Tile::Reveal()
{
	assert(state == Stage::HIDDEN);
	state = Stage::REVEALED;
}

bool Tile::hasProbe() const
{

	return state == Stage::PROBE;
}

void Tile::Probed()
{
	assert(!isRevealed());
	if (state == Stage::HIDDEN)
	{
		state = Stage::PROBE;
	}
	else
	{
		state = Stage::HIDDEN;
	}
}

void Tile::Draw(const Vei2& pos, JediField::State stage, Graphics& gfx)
{
	if (stage != JediField::State::IsDetected)
	{
		switch (state)
		{
		case Stage::HIDDEN:
			SpriteCodex::DrawTileTerminalButton(pos, gfx);
			break;
		case Stage::REVEALED:
			if (!hasjedi)
			{
				SpriteCodex::DrawTileNumber(pos, DroidSensorNumber, gfx);
			}
			else
			{
				Jmenu.DrawCharacters(pos, gfx);

			}
			break;
		case Stage::PROBE:
			SpriteCodex::DrawProbedroid(pos, gfx);
			break;
		}
	}
	else
	{
		switch (state)
		{
		case Stage::HIDDEN:
			if (hasjedi)
			{
				Jmenu.DrawCharacters(pos, gfx);
			}
			else {
				SpriteCodex::DrawTileTerminalButton(pos, gfx);
			}
			break;
		case Stage::REVEALED:
			if (!hasjedi)
			{
				SpriteCodex::DrawTileNumber(pos, DroidSensorNumber, gfx);


			}
			else {
				SpriteCodex::DrawProbedroidRed(pos, gfx);
			}
			break;
		case Stage::PROBE:
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
