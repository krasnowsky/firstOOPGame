#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Entities.h"

class Player : public Entities
{
    private:
        int speed = 3;

    public:
        Player(const char* fileName, int x, int y);
        ~Player() override;
        void Update(Entities &slime, Entities &snorlax);
        void Render() override;
        bool checkAlive() override;
};

#endif // PLAYER_H
