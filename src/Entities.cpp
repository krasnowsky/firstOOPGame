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
}

void Entities::Update()
{
}

void Entities::Render()
{
}

int Entities::getPositionX()
{
    return this -> xPos;
}

int Entities::getPositionY()
{
    return this -> yPos;
}

void Entities::setStats(int ad, int def, int hp)
{
    this -> AD = ad;
    this -> DEF = def;
    this -> HP = hp;
}

int Entities::getAD()
{
    return this -> AD;
}

int Entities::getDEF()
{
    return this -> DEF;
}

int Entities::getHP()
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

void Entities::setHP(int hp)
{
    this -> HP = hp;
}

bool Entities::checkAlive()
{
    return isAlive;
}

void Entities::setAD(int value) {
    this -> AD = value;
}

void Entities::setDEF(int value) {
    this -> DEF = value;
}
