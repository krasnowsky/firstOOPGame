#include "Dragon.h"

Dragon::Dragon(const char *fileName, int x, int y) : Entity(fileName, x, y)
{
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

void Dragon::Update(std::vector<std::shared_ptr<Entity>> entities)
{
    srcRect.h = 704;
    srcRect.w = 778;
    srcRect.x = 0;
    srcRect.y = 0;

    if(this -> getHP() <= 0)
    {
        isAlive = false;
        objTexture = TextureManager::LoadTexture("blank");
    }

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w / 6;
    destRect.h = srcRect.h / 6;

    int dragonPosY = this -> getPositionY();
    int playerPosY = entities[0] -> getPositionY();
    int dragonPosX = this -> getPositionX();
    int playerPosX = entities[0] -> getPositionX();

    if(abs(dragonPosX - playerPosX) < 50 && abs(dragonPosY - playerPosY) < 50 && isAlive)
    {
        if (entities[0] -> checkAlive())
        {
            int dmgAD = this -> getAD();
            int enemyHP = entities[0] -> getHP();
            int dmgADDealt;

            if(dmgAD == 0 || dmgAD <= entities[0] -> getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - entities[0] -> getDEF();

            entities[0] -> setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << entities[0] -> getName() << " with " << entities[0] -> getHP() << " HP" << std::endl;
        }
    }
}

void Dragon::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}
