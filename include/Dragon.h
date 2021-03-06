#ifndef GAME_DRAGON_H
#define GAME_DRAGON_H

#include "Entity.h"

class Dragon : public Entity
{
private:
    int speed = 2;
public:
    Dragon(const char* fileName, int x, int y);
    void Update(std::vector<std::shared_ptr<Entity>> entities);
    void Render() override;
};

#endif //GAME_DRAGON_H
