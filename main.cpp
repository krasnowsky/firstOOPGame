#include "Game.h"

std::shared_ptr<Game> game;

int main(int argv, char** args)
{
    const int FPS = 60;
    const int frameDelay = 1000/ FPS;

    Uint32 frameStart;
    int frameTime;

    game = std::make_shared<Game>();
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
