#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "CoruscantArt.h"
#include "ShipArt.h"
#include "DagobahArt.h"
#include "TatooineArt.h"
#include "EndingArt.h"
#include "MenuArt.h"
#include "Keyboard.h"

class Background
{
public:
	enum class Levels
	{
		TEMPLE,
		SHIP,
		TATO,
		DAGO,
		DEFUALT
	};
public:
	Background() = default;
	//background art selctions
	void Themenu(Graphics& gfx);
	void JediTemple(Graphics& gfx);
	void TheShip(Graphics& gfx);
	void YodaHut(Graphics& gfx);
	void ObiWanHut(Graphics& gfx);
	void EndWon(Graphics& gfx);
	void EndFailure(Graphics& gfx);
	//background selection
	void MenuSelect(Keyboard& kbd);
	void SaberDraw(Graphics& gfx);
	void DrawBackground(Graphics& gfx);

private:
	MenuArt menu;
	CoruscantArt coruscant;
	ShipArt ship;
	DagobahArt dagobah;
	TatooineArt tatooine;
	EndingArt end;
	Levels level = Levels::DEFUALT;
};