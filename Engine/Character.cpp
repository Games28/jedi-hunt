#include "Character.h"

Character::Character(Vec2 &head_loc, Vec2 & robe_loc, Vec2& saber_loc, void (ArtSaber::** arrayofArt)(int, int, int, Color*, Graphics&))
	:
	lightSaber(saber_loc, arrayofArt)
	
              
	//Head			Robe			Saber
	//{Vec2{110,192}, Vec2{100,240}, Vec2{210,282}},
	//{Vec2{637,195}, Vec2{600,240}, Vec2{580,282}} },
{
	artpos.head = head_loc;
	artpos.robe = robe_loc;
	lightSaber.loc = saber_loc;
	lightSaber.DrawSaber[0] = 0;
	lightSaber.DrawSaber[1] = 0;
	lightSaber.collider.Init(lightSaber.loc + Vec2(0, -100.0f), lightSaber.SaberBladeSize);
	//lightSaber.collider[1].Init(lightSaber.loc - Vec2(0, 100.0f), lightSaber.SaberBladeSize);
	//lightSaber.colliders[2].Init(lightSaber.loc + Vec2(7, 50.0f), lightSaber.SaberBladeSize);
	//lightSaber.colliders[3].Init(lightSaber.loc + Vec2(7, -100.0f), lightSaber.SaberBladeSize);
	
	
}



void Character::Move(Vec2 moveAmount)
{
	artpos.head += moveAmount;
	artpos.robe += moveAmount;
	lightSaber.Move(moveAmount);
	//SPACE RESPECING DEBUG COLLISION CODE!
	//for (int i = 0; i < 4; i++)
	{
		lightSaber.collider.Move(moveAmount);
	}
	collider.Move(moveAmount);
}




void Character::Draw(Graphics& gfx)
{
	(gfx.robes.*(DrawRobe))((int)artpos.robe.x, (int)artpos.robe.y, gfx);
	(gfx.heads.*(DrawHead))((int)artpos.head.x, (int)artpos.head.y, gfx);
	//if (lightSaber.isSelected1)
	{
		
		
		if (lightSaber.isdown)
		{
			(gfx.saber1.*(lightSaber.Draw[1]))((int)lightSaber.loc.x, (int)lightSaber.loc.y, 
												lightSaber.length, lightSaber.color, gfx);
			lightSaber.collider.DrawBox(gfx,Colors::Yellow);
			
		}
		else
		{
			(gfx.saber1.*(lightSaber.Draw[0]))((int)lightSaber.loc.x, (int)lightSaber.loc.y, 
												lightSaber.length, lightSaber.color, gfx);
			lightSaber.collider.DrawBox(gfx, Colors::Yellow);
			
		
		}
		
	}
	//if (lightSaber.isSelected2)
	{
		//(gfx.Thesaber.*(lightSaber.Draw[1]))((int)lightSaber.loc.x, (int)lightSaber.loc.y,
		//	lightSaber.length, lightSaber.color, gfx);
		//if (lightSaber.isdown)
		//{
		//	(gfx.saber2.*(lightSaber.Draw[3]))((int)lightSaber.loc.x, (int)lightSaber.loc.y,
		//		lightSaber.length, lightSaber.color, gfx);
		//	lightSaber.colliders[2].DrawBox(gfx, Colors::Green);
		//	
		//}
		//else
		//{
		//	(gfx.saber2.*(lightSaber.Draw[2]))((int)lightSaber.loc.x, (int)lightSaber.loc.y,
		//		lightSaber.length, lightSaber.color, gfx);
		//	lightSaber.colliders[3].DrawBox(gfx, Colors::Green);
		//
		//
		//}
	}
	//SPACE RESPECING DEBUG COLLISION CODE!
	collider.DrawBox(gfx, Colors::Blue);
	
}

void Character::SaberColorChange()
{
	int Red = lightSaber.color[0].GetR();
	int Blue = lightSaber.color[0].GetB();
	int Green = lightSaber.color[0].GetG();
	int increase = 3;
	
	if (ColorIncreasing)
	{
		
		if (Red >= 253 || Green >= 253 || Blue  >= 253)
		{
			ColorIncreasing = false;
		}
		else
		{
			lightSaber.color[0] = Color(Red+increase, Green+increase, Blue+increase );
		}

	}
	else
	{
		if (Red <= 0 || Green <= 0 || Blue <= 0)
		{
			ColorIncreasing = true;
		}
		else
		{
			lightSaber.color[0] = Color(Red-increase, Green-increase, Blue-increase);
		}

	}
}

void Character::SaberBackColorChange()
{
	float Red = 1.0f / (255.0f / (1 + lightSaber.color[0].GetR()));
	float Blue = 1.0f /(255.0f / (1 + lightSaber.color[0].GetB()));
	float Green = 1.0f /(255.0f / (1 + lightSaber.color[0].GetG()));
	char increase = 3;
	char MAX = 127;
	if (ColorIncreasing)
	{

		if (lightSaber.color[1].GetR() >= MAX || lightSaber.color[1].GetB() >= MAX || lightSaber.color[1].GetG() >= MAX)
		{
			ColorIncreasing = false;
		}
		else
		{
			
			Color blend = lightSaber.color[1];
			lightSaber.color[1] = Color(blend.GetR() + Red * increase, blend.GetG() + Green * increase, blend.GetB() + Blue * increase );
		}

	}
	else
	{
		if (lightSaber.color[1].GetR() <= 0 && lightSaber.color[1].GetB() <= 0 && lightSaber.color[1].GetG() <= 0)
		{
			ColorIncreasing = true;
		}
		else
		{
			Color blend = lightSaber.color[1];
			lightSaber.color[1] = Color(blend.GetR() - Red * increase, blend.GetG() - Green * increase, blend.GetB() - Blue * increase);
		}

	}
}
