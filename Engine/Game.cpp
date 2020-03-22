/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
    
}

void Game::UpdateModel()
{
    
        
        switch (gstate)
        {
        case GameState::MENU:
        {
           diff.selection(wnd.kbd);
            back.MenuSelect(wnd.kbd);
            //jfield->keySelection(wnd.kbd);
            TheDifficulty();
            
            
            if (wnd.kbd.KeyIsPressed(VK_RETURN))
            {
                gstate = GameState::GAMEPLAY;
            }
            break;
        }
        case GameState::GAMEPLAY:
        {
            
            CreateField(size.x, size.y, nJedi);
            while (!wnd.mouse.IsEmpty())
            {
                const auto e = wnd.mouse.Read();
                if (jfield->GetState() == JediField::State::Probing)
                {
                   
                    if (e.GetType() == Mouse::Event::Type::LPress)
                    {
                        const Vei2 mousePos = wnd.mouse.GetPos();
                        if (jfield->GetRect().Contains(mousePos))
                        {
                            jfield->OnRevealClick(mousePos);
                        }
                    }
                    else if (e.GetType() == Mouse::Event::Type::RPress)
                    {
                        const Vei2 mousePos = wnd.mouse.GetPos();
                        if (jfield->GetRect().Contains(mousePos))
                        {
                            jfield->OnProbeClick(mousePos);
                        }
                    }
                }

                if (jfield->GetState() == JediField::State::Winner || jfield->GetState() == JediField::State::IsDetected)
                {
                    gstate = GameState::END;
                    DestroyField();
                }
            }
            break;
        }
        case GameState::END:
        {
            if (wnd.kbd.KeyIsPressed(VK_BACK))
            {
                gstate = GameState::MENU;
            }
            break;
        }
        }

    
    
}

void Game::CreateField(int width, int height, int nJedi)
{
    assert(jfield == nullptr);
    jfield = new JediField(gfx.GetRect().GetCenter(), width, height, nJedi);
}

void Game::DestroyField()
{
    jfield->freeResources();
    delete jfield;
    jfield = nullptr;
}

void Game::TheDifficulty()
{
   
    if (diff.settings == Difficulty::Setting::EASY)
    {
        nJedi = 5;
        size = Vei2{ 8,4 };

    }
    else if (diff.settings == Difficulty::Setting::MEDIUM)
    {
        nJedi = 15;
        size = Vei2{ 14,7 };

    }
    else if (diff.settings == Difficulty::Setting::HARD)
    {
        nJedi = 45;
        size = Vei2{ 24,16 };

    }
   
}

void Game::ComposeFrame()
{
    switch (gstate)
    {
    case GameState::MENU:
    {
        back.Themenu(gfx);
        back.SaberDraw(gfx);
        //jfield->DrawSaber(gfx);
        diff.Draw(gfx);
        //menu.Draw(gfx);
       

        break;
    }
    case GameState::GAMEPLAY:
    {
        back.DrawBackground(gfx);
        jfield->Draw(gfx);
        break;
    }
    case GameState::END:
    {
        if (jfield->GetState() == JediField::State::Winner)
        {
            back.EndWon(gfx);
        }
        if (jfield->GetState() == JediField::State::IsDetected)
        {
            back.EndFailure(gfx);
        }
        break;
    }
    }
    
    
    
}
