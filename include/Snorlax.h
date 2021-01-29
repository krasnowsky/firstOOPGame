#ifndef GAME_SNORLAX_H
#define GAME_SNORLAX_H

#include "Entity.h"

class Snorlax : public Entity
{
private:
    int speed = 2;
    int topBorder = 480, bottomBorder = 620;
    bool isUp = true, isAttacked = false;
public:
    Snorlax(const char* fileName, int x, int y);
    void Update(Entity &enemy);
    void Render() override;
};



#endif //GAME_SNORLAX_H
