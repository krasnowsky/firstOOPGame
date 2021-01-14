#include <accctrl.h>
#include "Game.h"
#include "TextureManager.h"
#include "Entities.h"
#include "Player.h"


Player::Player(const char* fileName, int x, int y) : Entities(fileName, x, y)
{
    objTexture = TextureManager::LoadTexture(fileName);
    //std::cout << "New player joined the World." << std::endl;
    xPos = x;
    yPos = y;
}

Player::~Player()
{
    //std::cout << this -> name << " left the World." << std::endl;
}

void Player::Update()
{
    if(Game::event.type == SDL_KEYDOWN)
    {
        switch(Game::event.key.keysym.sym)
        {
        case SDLK_w:
            {
                //this -> movementY(-1);
                if(yPos > 0)
                {
                    this -> yPos -= speed;
                }

                break;
            }

        case SDLK_a:
            {
                //this -> movementX(-1);
                if(xPos > 0)
                {
                    this -> xPos -= speed;
                }

                break;
            }

        case SDLK_s:
            {
                //this -> movementY(1);
                if(yPos < 574)
                {
                    this -> yPos += speed;
                }

                break;
            }

        case SDLK_d:
            {
                //this -> movementX(1);
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

    /*if(Game::event.type == SDL_KEYUP)
    {
        switch(Game::event.key.keysym.sym)
        {
        case SDLK_w:
            {
                this -> movementY(0);
                break;
            }

        case SDLK_a:
            {
                this -> movementX(0);
                break;
            }

        case SDLK_s:
            {
                this -> movementY(0);
                break;
            }

        case SDLK_d:
            {
                this -> movementX(0);

                break;
            }

        default:
            {
                break;
            }
        }

    }*/

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

   // std::cout << "X: " << xPos << "Y: " << yPos << std::endl;
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
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}

bool Player::checkAlive()
{
    return isAlive;
}

