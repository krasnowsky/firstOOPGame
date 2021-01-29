#ifndef GAME_SHIELD_H
#define GAME_SHIELD_H

#include "Item.h"

class Shield : public Item
{
private:
    bool isTaken = false;
    int attrDef = 50;
public:
    Shield(const char* fileName, int x, int y);
    void UpdateItem(Player &player);
    void RenderItem() override;
};

#endif //GAME_SHIELD_H
