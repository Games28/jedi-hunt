#include "JediField.h"
#undef min
#undef max

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

void JediField::Tile::Reveal()
{
	assert(state == State::HIDDEN);
	state = State::REVEALED;
}

bool JediField::Tile::hasProbe() const
{
	
	return state == State::PROBE;
}

void JediField::Tile::Probed()
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

void JediField::Tile::Draw(const Vei2& pos, JediField::State stage, Graphics& gfx) 
{
	if (stage != JediField::State::IsDetected)
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

void JediField::Tile::DroidScanresults(int scancount)
{
	assert(DroidSensorNumber == -1);
	DroidSensorNumber = scancount;
}

RectI JediField::GetRect() const
{
	return RectI(topLeft, width *SpriteCodex::artsize, height * SpriteCodex::artsize);
}

JediField::JediField(const Vei2 center,int nJedi)
	:
	topLeft(center - Vei2(width * SpriteCodex::artsize, height * SpriteCodex::artsize) / 2)
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
		TileAt(spawnPos).Reveal();
	}
	
	
	for (Vei2 gridPos = { 0,0 }; gridPos.y < height; gridPos.y++)
	{
		for (gridPos.x = 0; gridPos.x < width; gridPos.x++)
		{
			TileAt(gridPos).DroidScanresults(DroidScanCount(gridPos));
		}
	}
	
	

}

void JediField::OnRevealClick(const Vei2& screenPos)
{
	if (jstate == State::Probing)
	{

		const Vei2 gridPos = ScreenToGrid(screenPos);
		assert(gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 &&
			gridPos.y < height);
		Tile& tile = TileAt(gridPos);
		if (!tile.isRevealed() && !tile.hasProbe())
		{
			tile.Reveal();
			if (tile.HasJedi())
			{
				jstate = State::IsDetected;

			}
			else if (JediFound())
			{
				jstate = State::Winner;
			}
		}
	}
	
}

void JediField::OnProbeClick(const Vei2& screenPos)
{
	if (jstate == State::Probing)
	{
		const Vei2 gridPos = ScreenToGrid(screenPos);
		assert(gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 &&
			gridPos.y < height);
		Tile& tile = TileAt(gridPos);
		if (!tile.isRevealed())
		{
			tile.Probed();
		}
	}
}

JediField::State JediField::GetState() const
{
	return jstate;
}

int JediField::DroidScanCount(const Vei2& gridpos)
{
	const int xStart = std::max(0, gridpos.x - 1);
	
	const int yStart = std::max(0, gridpos.y - 1);
	const int xEnd = std::min(width - 1, gridpos.x + 1);
	const int yEnd = std::min(height - 1, gridpos.y + 1);

	int count = 0;
	for (Vei2 gridPos = { xStart,yStart }; gridPos.y <= yEnd; gridPos.y++)
	{
		for (gridPos.x = xStart; gridPos.x <= xEnd; gridPos.x++)
		{
			if (TileAt(gridPos).HasJedi())
			{
				count++;
			}
		}
	}
	return count;
}

bool JediField::JediFound() const
{
	for (const Tile& j : Jfield)
	{
		if ((j.HasJedi() && !j.hasProbe()) ||
			(!j.HasJedi() && !j.isRevealed()))
		{
			return false;
		}
	}
	return true;
}

JediField::Tile& JediField::TileAt(const Vei2& gridpos)
{
	return Jfield[gridpos.y * width + gridpos.x];
}

Vei2 JediField::ScreenToGrid(const Vei2& ScreenPos)
{
	return (ScreenPos - topLeft) / SpriteCodex::artsize;
}

const JediField::Tile& JediField::TileAt(const Vei2 gridpos) const
{
	return Jfield[gridpos.y * width + gridpos.x];
}

void JediField::Draw(Graphics& gfx) 
{
	gfx.DrawRect(GetRect().GetExpanded(borderThickness), borderColor);
	gfx.DrawRect(GetRect(), SpriteCodex::baseColor);
	for (Vei2 gridPos = { 0,0 }; gridPos.y < height; ++gridPos.y)
	{
		for (gridPos.x = 0; gridPos.x < width; ++gridPos.x)
		{
			
			TileAt(gridPos).Draw(topLeft + gridPos * SpriteCodex::artsize,jstate, gfx);
		}
	}
}
