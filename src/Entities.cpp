#include "Game.h"
#include "TextureManager.h"
#include "Entities.h"
#include "Player.h"

Entities::Entities(const char* fileName, int x, int y)
{
    objTexture = TextureManager::LoadTexture(fileName);

    xPos = x;
    yPos = y;

}

Entities::~Entities()
{
    //dtor
}

void Entities::Update()
{

}

void Entities::Render()
{
     //SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}

int Entities::getPositionX()
{
    return this -> xPos;
}

int Entities::getPositionY()
{
    return this -> yPos;
}

void Entities::setStats(float ad, float def, float hp)
{
    this -> AD = ad;
    this -> DEF = def;
    this -> HP = hp;
}

float Entities::getAD()
{
    return this -> AD;
}

float Entities::getDEF()
{
    return this -> DEF;
}

float Entities::getHP()
{
    return this -> HP;
}

void Entities::setName(std::string nick)
{
    this -> name = nick;
}

std::string Entities::getName()
{
    return this -> name;
}

void Entities::movementX(int right)
{
    this -> xPos += right;
}

void Entities::movementY(int up)
{
    this -> yPos += up;
}

void Entities::getStats()
{
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "| " << this -> getName() << "'s stats:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "| " << "HP: " << this -> getHP() << std::endl;
    std::cout << "| " << "AD: " << this -> getAD() << std::endl;
    std::cout << "| " << "DEF: " << this -> getDEF() << std::endl;
    std::cout << "--------------------------------------" << std::endl << std::endl;
}

void Entities::setHP(float hp)
{
    this -> HP = hp;
}

bool Entities::checkAlive()
{
    return isAlive;
}

float Entities::setAD(float value) {
    this -> AD = value;
}

float Entities::setDEF(float value) {
    this -> DEF = value;
}
