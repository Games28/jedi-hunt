#include "JediField.h"

bool JediField::Tile::HasJedi() const
{
	return hasjedi;
}

void JediField::Tile::SpawnJedi()
{
	assert(!hasjedi);
	hasjedi = true;
}

bool JediField::Tile::isRevealed() const
{
	return state == State::REVEALED;
}

void JediField::Tile::Revealed()
{
	assert(state == State::HIDDEN);
	state = State::REVEALED;
}

bool JediField::Tile::hasProbe() const
{
	return state == State::PROBE;
}

void JediField::Tile::LaunchedProbe()
{
	assert(state == State::HIDDEN);
	state = State::PROBE;
}

void JediField::Tile::Draw(const Vei2& pos, Graphics& gfx) const
{
	switch (state)
	{
	case State::HIDDEN:
		SpriteCodex::DrawTileTerminalButton(pos, gfx);
		break;
	case State::REVEALED:
		if (!hasjedi)
		{
			SpriteCodex::DrawTile0(pos,gfx);
		}
		else{
			SpriteCodex::DrawR2d2(pos, gfx);
		}

		
		break;
	case State::PROBE:
		SpriteCodex::DrawProbedroid(pos, gfx);
		break;
	}
}

RectI JediField::GetRect() const
{
	return RectI(0, width *SpriteCodex::artsize, 0, height * SpriteCodex::artsize);
}

JediField::JediField(int nJedi)
{
	assert(nJedi > 0 && nJedi < width * height);
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xdist(0, width - 1);
	std::uniform_int_distribution<int> ydist(0, height - 1);

	for (int nSpawned = 0; nSpawned < nJedi; ++nSpawned)
	{
		Vei2 spawnPos;
		do
		{
			spawnPos = Vei2(xdist(rng), ydist(rng));
		} while (TileAt(spawnPos).HasJedi());
		TileAt(spawnPos).SpawnJedi();
	}
	//test code
	for (int pos = 0; pos < 120; pos++)
	{
		const Vei2 gPos = { xdist(rng), ydist(rng) };
		if (!TileAt(gPos).isRevealed())
		{
			TileAt(gPos).Revealed();
		}
		//vs this 
		Vei2 Pos;
		Pos = Vei2(xdist(rng), ydist(rng));
		TileAt(Pos).Revealed();
		
	}
	
}

JediField::Tile& JediField::TileAt(const Vei2& gridpos)
{
	return Jfield[gridpos.y * width + gridpos.x];
}

const JediField::Tile& JediField::TileAt(const Vei2 gridpos) const
{
	return Jfield[gridpos.y * width + gridpos.x];
}

void JediField::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetRect(), SpriteCodex::baseColor);
	for (Vei2 gridPos = { 0,0 }; gridPos.y < height; ++gridPos.y)
	{
		for (gridPos.x = 0; gridPos.x < width; ++gridPos.x)
		{
			
			TileAt(gridPos).Draw(gridPos * SpriteCodex::artsize, gfx);
		}
	}
}
