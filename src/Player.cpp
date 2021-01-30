#include "TextureManager.h"
#include "Player.h"
#include "Map.h"

Player::Player(const char* fileName, int x, int y) : Entity(fileName, x, y)
{
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

Player::~Player()
{
}

void Player::Update(std::vector<std::shared_ptr<Entity>> entities, Map &map)
{
    int playerPosX = this -> getPositionX();
    int playerPosY = this -> getPositionY();

    xTravelled = playerPosX / 32;
    yTravelled = playerPosY / 32;

    int blockUnder = map.getBlockUnder(yTravelled+2, xTravelled+2);

    if(Game::event.type == SDL_KEYDOWN)
    {
        switch(Game::event.key.keysym.sym)
        {
        case SDLK_w:
            {
                if(yPos > 0)
                {
                    if(blockUnder != 0)
                        this -> yPos -= speed;
                    else
                        this -> yPos += 32;
                }

                break;
            }

        case SDLK_a:
            {
                if(xPos > 0)
                {
                    if(blockUnder != 0)
                        this -> xPos -= speed;
                    else
                        this -> xPos += 32;
                }

                break;
            }

        case SDLK_s:
            {
                if(yPos < 660)
                {
                    if(blockUnder != 0)
                        this -> yPos += speed;
                    else
                        this -> yPos -= 32;
                }

                break;
            }

        case SDLK_d:
            {
                if(xPos < 1200)
                {
                    if(blockUnder != 0)
                        this -> xPos += speed;
                    else
                        this -> xPos -= 32;
                }
                break;
            }

        default:
            {
                break;
            }
        }
    }

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

    int slimePosX = entities[1] -> getPositionX();
    int slimePosY = entities[1] -> getPositionY();

    int snorlaxPosX = entities[2] -> getPositionX();
    int snorlaxPosY = entities[2] -> getPositionY();

    int dragonPosX = entities[3] -> getPositionX();
    int dragonPosY = entities[3] -> getPositionY();

    if(abs(playerPosX - slimePosX) < 17 && entities[1] -> checkAlive())
    {
            int dmgAD = this -> getAD();
            int enemyHP = entities[1] -> getHP();
            int dmgADDealt;

            if(dmgAD == 0 || dmgAD <= entities[1] -> getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - entities[1] -> getDEF();

            entities[1] -> setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << entities[1] -> getName() << " with " << entities[1] -> getHP() << " HP" << std::endl;
    }

    if(abs(playerPosX - snorlaxPosX) < 50 && abs(playerPosY - snorlaxPosY) < 50 && entities[2] -> checkAlive())
    {
            int dmgAD = this -> getAD();
            int enemyHP = entities[2] -> getHP();
            int dmgADDealt;

            if(dmgAD == 0 || dmgAD <= entities[2] -> getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - entities[2] -> getDEF();

            entities[2] -> setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << entities[2] -> getName() << " with " << entities[2] -> getHP() << " HP" << std::endl;
    }

    if(abs(playerPosX - dragonPosX) < 50 && abs(playerPosY - dragonPosY) < 50 && entities[3] -> checkAlive())
    {
        int dmgAD = this -> getAD();
        int enemyHP = entities[3] -> getHP();
        int dmgADDealt;

        if(dmgAD == 0 || dmgAD <= entities[3] -> getDEF()) dmgADDealt = 0;
        else  dmgADDealt = dmgAD - entities[3] -> getDEF();

        entities[3] -> setHP(enemyHP-dmgADDealt);
        std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << entities[3] -> getName() << " with " << entities[3] -> getHP() << " HP" << std::endl;
    }

    if(!entities[1] -> checkAlive() && !entities[2] -> checkAlive() && !entities[3] -> checkAlive())
    {
        objTexture = TextureManager::LoadTexture("../assets/teemoVICTORY.png");
        destRect.w = srcRect.w * 20;
        destRect.h = srcRect.h * 20;
        destRect.x = 500;
        destRect.y = 50;
    }

    if(this -> getHP() <= 0)
    {
        isAlive = false;
        objTexture = TextureManager::LoadTexture("../assets/teemoEND.png");
        destRect.w = srcRect.w * 20;
        destRect.h = srcRect.h * 20;
        destRect.x = 500;
        destRect.y = 50;
    }
}

void Player::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}

bool Player::checkAlive()
{
    return isAlive;
}

