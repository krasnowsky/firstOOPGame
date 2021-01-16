#ifndef GAME_SHIELD_H
#define GAME_SHIELD_H

#include "Items.h"

class Shield : public Items
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
