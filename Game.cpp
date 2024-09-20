#include "Game.hpp"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

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

    SDL_Surface* tmpSurface;
    tmpSurface = IMG_Load("ProjectPNG/katanna.png");
    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
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
    cnt++;
    destR.h =32*5;
    destR.w =32*5;


    std::cout<<cnt<<std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //where stuff whould be placed to renderer
    SDL_RenderCopy(renderer,playerTex,NULL,&destR);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Cleaned"<<std::endl;
}




