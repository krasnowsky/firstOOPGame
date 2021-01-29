#ifndef GAME_SLIME_H
#define GAME_SLIME_H

#include "Entity.h"

class Slime : public Entity
{
private:
    int speed = 2;
    int leftBorder = 289, rightBorder = 465;
    bool isRight = true, isAttacked = false;
public:
    Slime(const char* fileName, int x, int y);
    void Update(Entity &enemy);
    void Render() override;



};

#endif //GAME_SLIME_H
