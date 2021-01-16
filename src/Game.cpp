#include <Slime.h>
#include <Snorlax.h>
#include <Heal.h>
#include <Sword.h>
#include <Shield.h>
#include "Game.h"
#include "Player.h"
#include "Map.h"
#include <memory>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = std::make_shared<Player>("../assets/teemo.png", 0, 0);
    player -> setName("Super Hero");
    player -> setStats(120, 10, 2000);
    player -> getStats();

    slime = std::make_shared<Slime>("../assets/angryslime.png", 289,-50);
    slime -> setName("Maria Slime");
    slime -> setStats(20, 5, 200);
    slime -> getStats();

    snorlax = std::make_shared<Snorlax>("../assets/snorlax.png", 660, 300);
    snorlax -> setName("Sleepy Bear");
    snorlax -> setStats(15, 20, 400);
    snorlax -> getStats();

    potion = std::make_shared<Heal>("../assets/heal.png", 0, 300);
    sword = std::make_shared<Sword>("../assets/sword.png", 120, 250);
    shield = std::make_shared<Shield>("../assets/shield.png", 110, 150);

    Map1 = std::make_shared<Map>();
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);

    switch(event.type)
    {
    case SDL_QUIT:
        {
            isRunning = false;
            break;
        }

    default:
        {
            break;
        }
    }
}

void Game::update()
{
    player -> Update(*slime, *snorlax);
    slime -> Update(*player);
    snorlax -> Update(*player);
    potion -> UpdateItem(*player);
    sword -> UpdateItem(*player);
    shield -> UpdateItem(*player);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    Map1 -> DrawMap();
    slime -> Render();
    snorlax -> Render();
    potion -> RenderItem();
    sword -> RenderItem();
    shield -> RenderItem();
    player -> Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}

