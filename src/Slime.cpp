#include <Slime.h>

Slime::Slime(const char *fileName, int x, int y) : Entity(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

void Slime::Update(std::vector<std::shared_ptr<Entity>> entities) {
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    if(!isAttacked)
        {
        if(isRight)
        {
            xPos += speed;
            if(xPos > rightBorder)
            {
                isRight = false;
            }
        }
        else {
            xPos -= speed;
            if (xPos < leftBorder) {
                isRight = true;
            }
        }
    }


    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;

    if(this -> getHP() <= 0)
    {
        isAlive = false;
        objTexture = TextureManager::LoadTexture("../assets/angryslimeDEAD.png");
        destRect.y = 0;

    }

    int slimePos = this -> getPositionX();
    int playerPos = entities[0] -> getPositionX();

    if(abs(slimePos - playerPos) < 17 && isAlive)
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

void Slime::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}




