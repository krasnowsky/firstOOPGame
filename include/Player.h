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
        virtual ~Player();
        void Update();
        void Render();
        bool checkAlive();
};

#endif // PLAYER_H
