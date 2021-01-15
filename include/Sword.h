#ifndef GAME_SWORD_H
#define GAME_SWORD_H

#include "Items.h"

class Sword : public Items
{
private:
    bool isTaken = false;
    int attrDmg = 50;
public:
    Sword(const char* fileName, int x, int y);
    void UpdateItem(Player &player);
    void RenderItem();
};





#endif //GAME_SWORD_H
