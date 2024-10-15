    #include "Game.hpp"
    #include "TextureManager.hpp"
    #include "GameObject.hpp"
    #include "Map.hpp"
    #include "Player.hpp"
    #include "KeyboardInput.hpp"
    #include "Projectile.hpp"
    #include "Enemy.hpp"
    #include "Gun.hpp"
    #include "Disk.hpp"
    #include "Sword.hpp"
    #include "Collison.hpp"
    #include "EnemyManager.hpp"


    //inilize diffrent game objects with there type an a pointer
    Player* player;
    Map* map;
    KeyboardInput* Input;
    Collison* collison;
    EnemyManager* enemyManager; // Max 50 enemies, spawn every 2 seconds

    //weapons
    Disk* disk;
    Disk* disk2;
    Disk* disk3;
    Sword* sword;
    Sword* sword2;
    Sword* sword3;
    Gun* gun;
    Gun* gun2;
    Gun* gun3;

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
        //gets time
        timer = SDL_GetTicks(); // Record the start time
        //determinds if game is in fullscreen
        int flags = 0;
        if(fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        //inilizes sdl and creates both the window and renderer
        if(SDL_Init(SDL_INIT_EVERYTHING)==0)
        {
            //std::cout<<"Subsystems Initlized"<<std::endl;

                //Creates window
                window = SDL_CreateWindow(title, xpos, ypos, width, height,flags);
                if(window)
                {
                    //std::cout<<"Window Created"<<std::endl;
                }

                //Creates renderer
                renderer = SDL_CreateRenderer(this->window,-1,0);
                if(renderer)
                {
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                //std::cout << "Renderer Created" << std::endl;
                }

            
            isRunning = true;
        }else
        {
            isRunning = false;
        }
    std::cout << "Press 1 for Disk, 2 for Gun, and 3 for Sword" << std::endl;
    //inilize the diffrent obejets with there constructors

    player = new Player("ProjectPNG/Pig.png", 32, 32, 0, 0, 2, 100, 25, 4, 1);
    enemyManager=new EnemyManager(50, 2000,player);
    map = new Map();

//weapons
    //sword
    sword = new Sword("ProjectPNG/katanna.png",32,32,player, 1,5,0);
    sword2 = new Sword("ProjectPNG/sword2.png",32,32,player, 1,10,0);
    sword3 = new Sword("ProjectPNG/sword3.png",32,32,player, 1,20,0);
    //disk
    disk = new Disk("ProjectPNG/disk.png", 32, 32, player, 75.0, 70, 5,0.2,5); 
    disk2 = new Disk("ProjectPNG/disk2.png", 32, 32, player, 90.0, 70, 5,0.4,7);  
    disk3 = new Disk("ProjectPNG/disk3.png", 32, 32, player, 120.0, 70, 5,0.6,10);
    //gun
    gun = new Gun(player, "ProjectPNG/bullet.png", 32, 32, 2, 1, 1000);
    gun2 = new Gun(player, "ProjectPNG/bullet2.png", 32, 32, 2, 1, 700);
    gun3 = new Gun(player, "ProjectPNG/bullet3.png", 32, 32, 2, 1, 300);

    Input = new KeyboardInput();

    //menu
    Menu=new GameObject("ProjectPNG/Menu.png",0,0,640,960,1);
    HelpMenu=new GameObject("ProjectPNG/HelpMenu.png",0,0,640,960,1);
    SettingsMenu=new GameObject("ProjectPNG/SettingsMenu.png",0,0,640,960,1);
    }

void Game::handleEvents()
{
    // Exits the window
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

    // Handles keyboard inputs and what they do
    Input->KeyInputDetedctor(player);
}


 void Game::update()
{
    elapsedTime = (SDL_GetTicks() - timer) / 1000;

    if (Input->inGame == 1) {
        // In game view
        player->Update();
        enemyManager->Update(player);

        // Update the selected weapon
        if (Input -> weaponChoice == 1) { 
            //Disk
            if (elapsedTime <= level1) {
                disk->Update(0.1);
            } else if (elapsedTime > level1 && elapsedTime <= level2) {
                disk2->Update(0.1);
            }else if (elapsedTime>level2){
                disk3->Update(0.1);
            }
        } else if (Input->weaponChoice == 2) { 
         if(elapsedTime<=level1){
                gun->Shoot(45);
                gun->Update();
            }else if (elapsedTime>level1 && elapsedTime<=level2){
                gun2->Shoot(45);
                gun2->Update();
            } else if (elapsedTime>level2){
                gun3->Shoot(45);
                gun3->Update();
            }
        } else if (Input->weaponChoice == 3) { // Sword
            if (elapsedTime <= level1) {
                sword->Update();
            } else if (elapsedTime > level1 && elapsedTime <= level2) {
                sword2->Update();
            }else if (elapsedTime>level2){
                sword3->Update();
            }
        }
        // Check for collisions with enemies
        for (auto enemy : enemyManager->getEnemies()) {            
            if (collison->beenHit(enemy, player, 32 , 16)) {
                // Call reduceHealth if there's a collision
                player->reduceHealth(10); // Assuming 10 is the damage dealt
                std::cout << "Player health: " << player->getHealth() << std::endl;
                if (player->getHealth()<=0){
                  std::cout<<"Player has died. Returnig to menu"<<std::endl;
                  Input -> inGame = 0;
                  Input -> inMenu = 1;
                  player -> health = 100;
                }
            }
        }
    } else if (Input->inMenu == 1) {
        // In menu view
        Menu->Update();
    } else if (Input->inSettings == 1) {
        // Settings menu
        SettingsMenu->Update();
    } else if (Input->inHelpMenu == 1) {
        // Help menu
        HelpMenu->Update();
    }

    cnt++;
    //std::cout << cnt << std::endl;
}

    void Game::render()
{
    SDL_RenderClear(renderer);  // Clear the window

    if (Input->inGame == 1) {
        // In game view
        map->DrawMap();  // Render the map
        player->Render();  // Render the player
        enemyManager->Render();

        // Render the currently selected weapon based on currentWeapon value
        if (Input ->weaponChoice == 1) {  // Disk
            if (elapsedTime <= level1) {
                disk->Render();
            } else if (elapsedTime > level1 && elapsedTime <= level2) {
                disk2->Render();
            } else if (elapsedTime > level2){
                disk3-> Render();
            }
        } else if (Input ->weaponChoice == 2) { 
            if (elapsedTime<=level1){
                gun->Render();
            } else if (elapsedTime>level1 && elapsedTime<=level2){
                gun2->Render();
            } else if (elapsedTime>level2){
                gun3 ->Render();
            }
        } else if (Input->weaponChoice == 3) {  
            if (elapsedTime<=level1){
                sword->Render();
            } else if (elapsedTime>level1 && elapsedTime<=level2){
                sword2->Render();
            } else if (elapsedTime>level2){
                sword3 ->Render();
            }
        }

    } else if (Input->inMenu == 1) {
        // In menu view
        Menu->Render();
    } else if (Input->inSettings == 1) {
        // Settings menu
        SettingsMenu->Render();
    } else if (Input->inHelpMenu == 1) {
        // Help menu
        HelpMenu->Render();
    }

    SDL_RenderPresent(renderer);  // Present everything to the screen
}

    void Game::clean()
    {    
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        

        //std::cout << "Game Cleaned"<<std::endl;
    }

