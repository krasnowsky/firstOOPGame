#ifndef MAP_H
#define MAP_H
#include "Game.h"

class Map
{
    public:
        Map();
        virtual ~Map();

        void LoadMap(int arr[20][25]);
        void DrawMap();

    private:
        SDL_Rect src, dest;

        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        int MapTexture[20][25];
};

#endif // MAP_H
