#ifndef GAME_SLIME_H
#define GAME_SLIME_H

#include "Entities.h"

class Slime : public Entities
{
private:
    int speed = 2;
    int leftBorder = 289, rightBorder = 465;
    bool isRight = true, isAttacked = false;
public:
    Slime(const char* fileName, int x, int y);
    void Update(Entities &enemy);
    void Render() override;



};

#endif //GAME_SLIME_H
