#ifndef MAP_H
#define MAP_H
#include "Game.h"

class Map
{
    public:
        Map();
        virtual ~Map();

        void LoadMap(int arr[23][40]);
        void DrawMap();

        int getBlockUnder(int p_x, int p_y);

    private:
        SDL_Rect src, dest;

        SDL_Texture* cobble;
        SDL_Texture* sand;
        SDL_Texture* lava;

        int MapTexture[23][40];
};

#endif // MAP_H
