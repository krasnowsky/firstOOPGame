#include "Game.h"
#include "TextureManager.h"
#include "Entity.h"
#include "Player.h"

Entity::Entity(const char* fileName, int x, int y)
{
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

Entity::~Entity()
{
}

void Entity::Update()
{

}

void Entity::Render()
{
}

int Entity::getPositionX()
{
    return this -> xPos;
}

int Entity::getPositionY()
{
    return this -> yPos;
}

void Entity::setStats(int ad, int def, int hp)
{
    this -> AD = ad;
    this -> DEF = def;
    this -> HP = hp;
}

int Entity::getAD()
{
    return this -> AD;
}

int Entity::getDEF()
{
    return this -> DEF;
}

int Entity::getHP()
{
    return this -> HP;
}

void Entity::setName(std::string nick)
{
    this -> name = nick;
}

std::string Entity::getName()
{
    return this -> name;
}

void Entity::getStats()
{
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "| " << this -> getName() << "'s stats:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "| " << "HP: " << this -> getHP() << std::endl;
    std::cout << "| " << "AD: " << this -> getAD() << std::endl;
    std::cout << "| " << "DEF: " << this -> getDEF() << std::endl;
    std::cout << "--------------------------------------" << std::endl << std::endl;
}

void Entity::setHP(int hp)
{
    this -> HP = hp;
}

bool Entity::checkAlive()
{
    return isAlive;
}

void Entity::setAD(int value) {
    this -> AD = value;
}

void Entity::setDEF(int value) {
    this -> DEF = value;
}
