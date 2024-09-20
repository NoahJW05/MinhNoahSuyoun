#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::initilize(const char* title, int xpos, int ypos, int width, int height,bool fullscreen) 
{
    //determinds if game is in fullscreen
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    //inilizes sdl and creates both the window and renderer
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        std::cout<<"Subsystems Initlized"<<std::endl;

            //Creates window
            window = SDL_CreateWindow(title, xpos, ypos, width, height,flags);
            if(window)
            {
                std::cout<<"Window Created"<<std::endl;
            }

            //Creates renderer
            renderer = SDL_CreateRenderer(this->window,-1,0);
            if(renderer)
            {
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            std::cout << "Renderer Created" << std::endl;
            }

        
        isRunning = true;
    }else
    {
        isRunning = false;
    }

   player = new GameObject("ProjectPNG/GrassTopRightCorner.png",0,0);
   map = new Map();

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    player->Update();
    cnt++;


    std::cout<<cnt<<std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //where stuff whould be placed to renderer
    map->DrawMap();
    //player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Cleaned"<<std::endl;
}




