#ifndef GAME_SWORD_H
#define GAME_SWORD_H

#include "Item.h"

class Sword : public Item
{
private:
    bool isTaken = false;
    int attrDmg = 10;
public:
    Sword(const char* fileName, int x, int y);
    void UpdateItem(Player &player);
    void RenderItem() override;
};





#endif //GAME_SWORD_H
