#pragma once

#include "Graphics.h"
#include "Vei2.h"
#include "Stars.h"
#include "CoruscantArt.h"
#include "ShipArt.h"
#include "DagobahArt.h"
#include "TatooineArt.h"
#include "ArtBackground.h"
#include "Colors.h"
#include "EndingArt.h"
#include "MenuArt.h"
#include "Selection.h"
#include <random>

class Background
{
public:
	Background() = default;
	void Themenu(Graphics& gfx);
	void JediTemple(Graphics& gfx);
	void TheShip(Graphics& gfx);
	void YodaHut(Graphics& gfx);
	void ObiWanHut(Graphics& gfx);
	void EndWon(Graphics& gfx);
	void EndFailure(Graphics& gfx);
	

private:
	Selection select;
	
	MenuArt menuart;
	CoruscantArt coruscant;
	ShipArt ship;
	DagobahArt dagobah;
	TatooineArt tatooine;
	EndingArt end;
};