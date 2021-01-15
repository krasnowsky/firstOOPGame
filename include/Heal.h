#ifndef GAME_HEAL_H
#define GAME_HEAL_H

#include "Items.h"

class Heal : public Items
{
private:
    bool isTaken = false;
public:
    Heal(const char* fileName, int x, int y);
    void UpdateItem(Player &player);
    void RenderItem();
};

#endif //GAME_HEAL_H
