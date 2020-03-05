#pragma once

#include "Graphics.h"
#include "Vei2.h"

class SpriteCodex
{
public:
	// width and height of all tiles
	static constexpr int tileSize = 16;
	// base color for all tiles
	static constexpr Color baseColor = Colors::Black;
	// 16x16 tile sprites assume (192,192,192) background and top left origin
	static void DrawTile0( const Vei2& pos,Graphics& gfx );
	static void DrawTile1( const Vei2& pos,Graphics& gfx );
	static void DrawTile2( const Vei2& pos,Graphics& gfx );
	static void DrawTile3( const Vei2& pos,Graphics& gfx );
	static void DrawTile4( const Vei2& pos,Graphics& gfx );
	static void DrawTile5( const Vei2& pos,Graphics& gfx );
	static void DrawTile6( const Vei2& pos,Graphics& gfx );
	static void DrawTile7( const Vei2& pos,Graphics& gfx );
	static void DrawTile8( const Vei2& pos,Graphics& gfx );
	static void DrawTileButton( const Vei2& pos,Graphics& gfx );
	static void DrawTileCross( const Vei2& pos,Graphics& gfx );
	static void DrawTileFlag( const Vei2& pos,Graphics& gfx );
	static void DrawTileBomb( const Vei2& pos,Graphics& gfx );
	static void DrawTileBombRed( const Vei2& pos,Graphics& gfx );

	//star wars art
	static constexpr int artsize = 28;

	void DrawLeia(const Vei2& pos, Graphics& gfx);
	void DrawLeiaAlert(const Vei2& pos, Graphics& gfx);
	void DrawYoda(const Vei2& pos, Graphics& gfx);
	void DrawYodaAlert(const Vei2& pos, Graphics& gfx);
	void DrawObiwan(const Vei2& pos, Graphics& gfx);
	void DrawObiwanAlert(const Vei2& pos, Graphics& gfx);
	void DrawR2d2(const Vei2& pos, Graphics& gfx);
	void DrawR2d2Alert(const Vei2& pos, Graphics& gfx);
	static void DrawProbedroid(const Vei2& pos, Graphics& gfx);
	static void DrawProbedroidRed(const Vei2& pos, Graphics& gfx);
	static void DrawTileTerminalButton(const Vei2& pos, Graphics& gfx);
	


	//Tile selector function valid input 0-8
	static void DrawTileNumber(const Vei2& pos, int n, Graphics& gfx);
};