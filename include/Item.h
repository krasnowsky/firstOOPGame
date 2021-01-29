#ifndef GAME_ITEMS_H
#define GAME_ITEMS_H

#include "Player.h"

class Item
{
protected:
    int PositionX;
    int PositionY;

    bool isTaken = false;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
public:
    Item(const char* fileName, int x, int y);
    virtual void UpdateItem();
    virtual void RenderItem();
};

#endif //GAME_ITEMS_H
