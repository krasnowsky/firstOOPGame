#ifndef GAME_SNORLAX_H
#define GAME_SNORLAX_H

#include "Entities.h"

class Snorlax : public Entities
{
private:
    int speed = 2;
    int topBorder = 100, bottomBorder = 400;
    bool isUp = true, isAttacked = false;
public:
    Snorlax(const char* fileName, int x, int y);
    void Update(Entities &enemy);
    void Render() override;
};



#endif //GAME_SNORLAX_H
