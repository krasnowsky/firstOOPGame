#include "Game.h"
#include "TextureManager.h"
#include "Entities.h"
#include "Player.h"

Player::Player(const char* fileName, int x, int y) : Entities(fileName, x, y)
{
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

Player::~Player()
{
}

void Player::Update(Entities &slime, Entities &snorlax)
{
    if(Game::event.type == SDL_KEYDOWN)
    {
        switch(Game::event.key.keysym.sym)
        {
        case SDLK_w:
            {
                if(yPos > 0)
                {
                    this -> yPos -= speed;
                }

                break;
            }

        case SDLK_a:
            {
                if(xPos > 0)
                {
                    this -> xPos -= speed;
                }

                break;
            }

        case SDLK_s:
            {
                if(yPos < 574)
                {
                    this -> yPos += speed;
                }

                break;
            }

        case SDLK_d:
            {
                if(xPos < 740)
                {
                    this -> xPos += speed;
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

    int playerPosX = this -> getPositionX();
    int playerPosY = this -> getPositionY();

    int slimePosX = slime.getPositionX();

    int snorlaxPosX = snorlax.getPositionX();
    int snorlaxPosY= snorlax.getPositionY();

    if(abs(playerPosX - slimePosX) < 17 && slime.checkAlive())
    {
            int dmgAD = this -> getAD();
            int enemyHP = slime.getHP();
            int dmgADDealt;

            if(dmgAD == 0 || dmgAD <= slime.getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - slime.getDEF();

            slime.setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << slime.getName() << " with " << slime.getHP() << " HP" << std::endl;
    }

    if(abs(playerPosX - snorlaxPosX) < 50 && abs(playerPosY - snorlaxPosY) < 50 && snorlax.checkAlive())
    {
            int dmgAD = this -> getAD();
            int enemyHP = snorlax.getHP();
            int dmgADDealt;

            if(dmgAD == 0 || dmgAD <= snorlax.getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - snorlax.getDEF();

            snorlax.setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt " << dmgADDealt << " DMG leaving " << snorlax.getName() << " with " << snorlax.getHP() << " HP" << std::endl;
    }

    //std::cout << "x: " << playerPosX << " y: " << playerPosY << std::endl;

    if(!slime.checkAlive() && !snorlax.checkAlive())
    {
        objTexture = TextureManager::LoadTexture("../assets/teemoVICTORY.png");
        destRect.w = srcRect.w * 20;
        destRect.h = srcRect.h * 20;
        destRect.x = 64;
        destRect.y = 0;
    }

    if(this -> getHP() <= 0)
    {
        isAlive = false;
        objTexture = TextureManager::LoadTexture("../assets/teemoEND.png");
        destRect.w = srcRect.w * 20;
        destRect.h = srcRect.h * 20;
        destRect.x = 64;
        destRect.y = 0;
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

