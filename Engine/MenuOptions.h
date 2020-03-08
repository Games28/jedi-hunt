#pragma once
class MenuOptions
{
public:
	enum class Difficulty
	{
		EASY,
		MEDIUM,
		HARD,
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


public:
	 Difficulty difficulty = Difficulty::DEFAULT;
	 Characters characters = Characters::DEFAULT;
	 Levels levels = Levels::DEFAULT;
};

