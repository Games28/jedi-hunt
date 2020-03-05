#include "Background.h"


void Background::Themenu(Graphics& gfx)
{
	menu.Window(gfx);
	menu.Thestars(gfx);
	menu.Midline(gfx);
	menu.Theemperor(355, 180, gfx);
	menu.Throne(gfx);
	menu.Vader(270, 120, gfx);
	menu.EmperorGuard(100, 120, gfx);
	menu.EmperorGuard(600, 120, gfx);
	menu.GuardSaber(110, 90, gfx);
	menu.GuardSaber(610, 90, gfx);
	menu.Projector(170, 350, gfx);
	Vei2 pos{ 140,120 };
	Vei2 pos1{ 150,140 };
	
	menu.Projection(140, 120, gfx);
	menu.SaberColorChange();
}

void Background::JediTemple(Graphics& gfx)
{
	Vei2 pos = { 0,0 };
	coruscant.JediTemple(pos, gfx);
	coruscant.StarAnimation(gfx);
}

void Background::TheShip(Graphics& gfx)
{
	Vei2 pos = { 0,0 };
	ship.LeiaHidout(pos, gfx);
	ship.LightsAnimation(pos, gfx);
	
}

void Background::YodaHut(Graphics& gfx)
{
	Vei2 pos = { 0,0 };
	dagobah.WaveAnimation(pos, gfx);
	dagobah.YodaHut(pos, gfx);
	
}

void Background::ObiWanHut(Graphics& gfx)
{
	Vei2 pos1 = { 0,0 };
	tatooine.ObiwanHut(pos1, gfx);
	tatooine.SunAnimation(pos1, gfx);

}

void Background::EndWon(Graphics& gfx)
{
	Vei2 pos = { 0,0 };
	end.VaderVictory(pos,gfx);
	Vei2 pos1 = { 400,100 };
	end.TheVictory(pos1, gfx);


}

void Background::EndFailure(Graphics& gfx)
{
	Vei2 pos = { 0,0 };
	end.VaderFailure(pos, gfx);
	Vei2 pos1 = { 400,100 };
	end.TheFailure(pos1, gfx);
}
