#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "KeyboardInput.hpp"
#include "Enemy.hpp"
#include "Collison.hpp"
#include "Gun.hpp"
#include "Sword.hpp"
#include "Disk.hpp"



//inilize diffrent game objects with there type an a pointer
Player* player;
Enemy* enemy;

//weapons
Disk* disk;
Sword* sword;

//input management and map
Map* map;
KeyboardInput* Input;

//collison detection class
Collison* collison;

//diffrent menus
GameObject* Menu;
GameObject* HelpMenu;
GameObject* SettingsMenu;
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

//inilize the diffrent obejets with there constructors
   player = new Player("ProjectPNG/Police.png",32,32,0,0,2,100,25,4);
   enemy = new Enemy("ProjectPNG/Demon.png",32,32,960/2,640/2,2,player);
//weapons
   disk = new Disk("ProjectPNG/disk.png", 32, 32, player, 75.0f, 70, 5, 0.2, 20);
   sword = new Sword("ProjectPNG/katanna.png", 32, 32, player, 1, 1, 0, 0);
   // map and input inilize
   map = new Map();
   Input = new KeyboardInput();

//collison inlized
    collison=new Collison();
    
//menu
   Menu=new GameObject("ProjectPNG/Menu.png",0,0,640,960,1);
   HelpMenu=new GameObject("ProjectPNG/HelpMenu.png",0,0,640,960,1);
   SettingsMenu=new GameObject("ProjectPNG/SettingsMenu.png",0,0,640,960,1);
}

void Game::handleEvents()
{
    //exits the window
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
//handels keyboardInputs and what they do
    Input->KeyInputDetedctor(player,enemy);

}

void Game::update()
{
    if(Input->inGame==1){
        //in game view
        player->Update();

        disk->Update(0.1f);
        sword->Update();

        enemy->FollowPlayer(player);
        enemy->Update();    
        
    }else if(Input->inMenu==1){
        //in menu view
        Menu->Update();

    }else if(Input->inSettings==1){
        //settings menu
         SettingsMenu->Update();

    }else if(Input->inHelpMenu==1){
        //help menu
        HelpMenu->Update();

    }

    bool beenHit=collison->enemyHitByDisk(enemy,disk,16,32);
    cnt++;


    std::cout<<beenHit<<std::endl;


}

void Game::render()
{
    SDL_RenderClear(renderer);
    //where stuff whould be placed to renderer/controls which menu 
    //state the games in menu or game

    if(Input->inGame==1){
        //in game view
        map->DrawMap();
        player->Render();

        disk->Render();
        sword->Render();

        enemy->Render();

        
    }else if(Input->inMenu==1){
        //in menu view
        Menu->Render();

    }else if(Input->inSettings==1){
        //settings menu
         SettingsMenu->Render();

    }else if(Input->inHelpMenu==1){
        //help menu
        HelpMenu->Render();

    }



    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Cleaned"<<std::endl;
}




