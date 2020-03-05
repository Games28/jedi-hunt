#pragma once
class Selection
{
public:
	enum class Difficulty
	{
		EASY,
		MEDIUM,
		HARD,
		default
	};
	enum class Characters
	{
		LEIA,
		OBIWAN,
		YODA,
		R2D2,
		default
	};
	enum class Levels
	{
		TATO,
		DAGO,
		TEMPLE,
		SHIP,
		default
	};
public:
	Levels level = Levels::default;
	Characters character = Characters::default;
	Difficulty difficulty = Difficulty::default;
};
