#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Entity.h"

class Player : public Entity
{
    private:
        int speed = 3;
        int xTravelled, yTravelled;

    public:
        Player(const char* fileName, int x, int y);
        ~Player() override;
        void Update(std::vector<std::shared_ptr<Entity>> entities, Map &map);
        void Render() override;
        bool checkAlive() override;
};

#endif // PLAYER_H
