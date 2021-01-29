#include "Dragon.h"

Dragon::Dragon(const char *fileName, int x, int y) : Entity(fileName, x, y)
{
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

void Dragon::Update(Entity &enemy)
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
    int playerPosY = enemy.getPositionY();
    int dragonPosX = this -> getPositionX();
    int playerPosX = enemy.getPositionX();

    if(abs(dragonPosX - playerPosX) < 50 && abs(dragonPosY - playerPosY) < 50 && isAlive)
    {
        if (enemy.checkAlive())
        {
            int dmgAD = this -> getAD();
            int enemyHP = enemy.getHP();
            int dmgADDealt;

            if(dmgAD == 0 || dmgAD <= enemy.getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - enemy.getDEF();

            enemy.setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << enemy.getName() << " with " << enemy.getHP() << " HP" << std::endl;
        }
    }
}

void Dragon::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}
