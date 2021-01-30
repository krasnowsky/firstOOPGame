#include <Snorlax.h>

Snorlax::Snorlax(const char *fileName, int x, int y) : Entity(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

void Snorlax::Update(std::vector<std::shared_ptr<Entity>> entities) {
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
    int playerPosY = entities[0] -> getPositionY();
    int snorlaxPosX = this -> getPositionX();
    int playerPosX = entities[0] -> getPositionX();

    if(abs(snorlaxPosX - playerPosX) < 50 && abs(snorlaxPosY - playerPosY) < 50 && isAlive)
    {
        isAttacked = true;
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

void Snorlax::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}

