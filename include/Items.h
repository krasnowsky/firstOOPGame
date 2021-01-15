#ifndef GAME_ITEMS_H
#define GAME_ITEMS_H

#include "Player.h"

class Items
{
protected:
    int PositionX;
    int PositionY;

    bool isTaken = false;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
public:
    Items(const char* fileName, int x, int y);
    virtual void UpdateItem();
    virtual void RenderItem();
};

#endif //GAME_ITEMS_H
