#include <Snorlax.h>

Snorlax::Snorlax(const char *fileName, int x, int y) : Entities(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

void Snorlax::Update(Entities &enemy) {
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    if(!isAttacked)
    {
        if(isUp)
        {
            yPos += speed;
            if(yPos >= bottomBorder)
            {
                isUp = false;
            }
        }
        else {
            yPos -= speed;
            if (yPos <= topBorder) {
                isUp = true;
            }
        }
    }

    if(this -> getHP() <= 0)
    {
        isAlive = false;
        objTexture = TextureManager::LoadTexture("../assets/snorlaxDEAD.png");
    }

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;

    int snorlaxPosY = this -> getPositionY();
    int playerPosY = enemy.getPositionY();
    int snorlaxPosX = this -> getPositionX();
    int playerPosX = enemy.getPositionX();

    if(abs(snorlaxPosX - playerPosX) < 50 && abs(snorlaxPosY - playerPosY) < 50 && isAlive)
    {
        isAttacked = true;
        if (enemy.checkAlive())
        {
            float dmgAD = this -> getAD();
            float enemyHP = enemy.getHP();
            float dmgADDealt;

            if(dmgAD == 0 || dmgAD <= enemy.getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - enemy.getDEF();

            enemy.setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << enemy.getName() << " with " << enemy.getHP() << " HP" << std::endl;
        }
    }
}

void Snorlax::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}

