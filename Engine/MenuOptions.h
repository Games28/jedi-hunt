#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "MenuArt.h"
#include "RectI.h"
#include "Mouse.h"
class MenuOptions
{
public:
	enum class Difficulty
	{
		EASY,
		MEDIUM,
		HARD,
		EXTREME,
		DEFAULT
	};
	enum class Characters
	{
		LEIA,
		OBIWAN,
		YODA,
		R2D2,
		DEFAULT
	};
	enum class Levels
	{
		TATO,
		DAGO,
		TEMPLE,
		SHIP,
		DEFAULT
	};
private:
	class button
	{
	public:
		button() = default;
		button(const Vei2& pos);
		void Draw(Graphics& gfx);
		bool madeContact(const Vei2& pos);
		void resetContact();
		void SetContact();
		bool isContacted();

	private:
		RectI rect;
		Vei2 pos;
		bool contacted = false;
	};

public:
	MenuOptions() = default;
	MenuOptions(const Vei2& pos);
	void ProcessMouse(const Mouse::Event& e);
	void Resetcontacts();
public: //art


	void Draw(Graphics& gfx);
	void Menuart(Vei2& pos, Graphics& gfx);
	static void Menuhighlight(Vei2& pos, Graphics& gfx);
	void Projection(Vei2& pos, Graphics& gfx);

private:
	static constexpr int maxhighlight = 12;
	static constexpr int highlightWidth = 88;
	static constexpr int highlightHeight = 35;
	 Difficulty difficulty = Difficulty::DEFAULT;
	 Characters characters = Characters::DEFAULT;
	 Levels levels = Levels::DEFAULT;
	 MenuArt art;
	 button buttons[maxhighlight];

	 /*Menuhighlight(Vei2(200, 158), gfx);
 
	 
	 menu.Projector(170, 350, gfx);
	Vei2 pos{ 140,120 };
	Vei2 pos1{ 150,140 };
	
	menu.Projection(140, 120, gfx);*/
};

