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
	menu.ProjectionColorChange();
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

void Background::MenuSelect(Keyboard& kbd)
{
	if (kbd.KeyIsPressed('L'))
	{
		if (kbd.KeyIsPressed('1'))
		{
			level = Levels::TATO;
		}
		else if (kbd.KeyIsPressed('2'))
		{
			level = Levels::DAGO;
		}
		else if (kbd.KeyIsPressed('3'))
		{
			level = Levels::SHIP;
		}
		else if (kbd.KeyIsPressed('4'))
		{
			level = Levels::TEMPLE;
		}
	}
}

void Background::SaberDraw(Graphics& gfx)
{
	menu.MenuSelection(Vei2{ 140, 120 }, gfx);
	if (level == Levels::TATO)
	{
		menu.GreenSaber(Vei2(320, 185), gfx);
	}
	else if (level == Levels::DAGO)
	{
		menu.GreenSaber(Vei2(320, 220), gfx);
	}
	else if (level == Levels::SHIP)
	{
		menu.GreenSaber(Vei2(320, 255), gfx);
	}
	else if (level == Levels::TEMPLE)
	{
		menu.GreenSaber(Vei2(320, 295), gfx);
	}
}

void Background::DrawBackground(Graphics& gfx)
{
	if (level == Levels::TATO)
	{
		ObiWanHut(gfx);
	}
	else if (level == Levels::DAGO)
	{
		YodaHut(gfx);
	}
	else if (level == Levels::SHIP)
	{
		TheShip(gfx);
	}
	else if (level == Levels::TEMPLE)
	{
		JediTemple(gfx);
	}
}
