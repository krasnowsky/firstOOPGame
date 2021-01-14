#include <iostream>
#include "Game.h"

Game *game = nullptr;

int main(int argv, char** args)
{
    const int FPS = 60;
    const int frameDelay = 1000/ FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game -> init("Beat The Dragon v1.0", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while(game -> running())
    {
        frameStart = SDL_GetTicks();

        game -> handleEvents();
        game -> update();
        game -> render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game -> clean();

    return 0;
}

/*World Noxus;

    Noxus.worldInit();

    while(Noxus.checkIsRunning())
    {
        Player firstChamp;
        Player secondChamp;

        firstChamp.setName("Darius");
        firstChamp.setStats(150, 0, 60, 30, 2000, 600);

        secondChamp.setName("Lux");
        secondChamp.setStats(30, 200, 20, 20, 1300, 800);

        firstChamp.setPosition(0,0);
        secondChamp.setPosition(0,0);

        std::cout << firstChamp.getName() << " is on X: " << firstChamp.getPositionX() << " Y: " << firstChamp.getPositionY() << std::endl;
        std::cout << secondChamp.getName() << " is on X: " << secondChamp.getPositionX() << " Y: " << secondChamp.getPositionY() << std::endl;

        firstChamp.movement(2,4,0,0);
        secondChamp.movement(3,5,0,0);

        std::cout << firstChamp.getName() << " is on X: " << firstChamp.getPositionX() << " Y: " << firstChamp.getPositionY() << std::endl;
        std::cout << secondChamp.getName() << " is on X: " << secondChamp.getPositionX() << " Y: " << secondChamp.getPositionY() << std::endl;

        firstChamp.getStats();
        secondChamp.getStats();

        firstChamp.attack(secondChamp);

        firstChamp.getStats();
        secondChamp.getStats();

        secondChamp.attack(firstChamp);

        firstChamp.getStats();
        secondChamp.getStats();

        Noxus.worldEnd();
    }*/
