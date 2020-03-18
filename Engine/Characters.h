#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "Keyboard.h"
class Characters
{
public:
	enum class characterOptions 
	{
		LEIA,
		OBIWAN,
		YODA,
		R2D2,
		BLUE,
		DEFAULT
	};
public:
	//art
	static void BlueSaber(Vei2& pos, Graphics& gfx);
	static void DrawLeia(const Vei2& pos, Graphics& gfx);
	static void DrawLeiaAlert(const Vei2& pos, Graphics& gfx);
	static void DrawYoda(const Vei2& pos, Graphics& gfx);
	static void DrawYodaAlert(const Vei2& pos, Graphics& gfx);
	static void DrawObiwan(const Vei2& pos, Graphics& gfx);
	static void DrawObiwanAlert(const Vei2& pos, Graphics& gfx);
	static void DrawR2d2(const Vei2& pos, Graphics& gfx);
	static void DrawR2d2Alert(const Vei2& pos, Graphics& gfx);
	static void DrawProbedroid(const Vei2& pos, Graphics& gfx);
	static void DrawProbedroidRed(const Vei2& pos, Graphics& gfx);
	static void DrawTileTerminalButton(const Vei2& pos, Graphics& gfx);
	//selection
	characterOptions& currentState(characterOptions& State);
	static void DrawCharacters(const Vei2& pos, Graphics& gfx, characterOptions& chopts);
	static void DrawCharactersAlert(const Vei2& pos, Graphics& gfx, characterOptions& chopts);

private:
	//characterOptions charoptions = characterOptions::DEFAULT;


};

