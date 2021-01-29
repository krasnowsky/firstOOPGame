#ifndef GAME_HEAL_H
#define GAME_HEAL_H

#include "Item.h"

class Heal : public Item
{
private:
    bool isTaken = false;
public:
    Heal(const char* fileName, int x, int y);
    void UpdateItem(Player &player);
    void RenderItem() override;
};

#endif //GAME_HEAL_H
