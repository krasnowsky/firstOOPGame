#ifndef ENTITIES_H
#define ENTITIES_H

#include <iostream>
#include <string>
#include "Game.h"
#include "TextureManager.h"
#include <vector>

class Entities
{
    protected:
        std::string name;

        int xPos;
        int yPos;

        int HP;
        int AD;
        int DEF;

        bool isAlive = true;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;

    public:
        Entities(const char* fileName, int x, int y);
        virtual ~Entities();


        virtual int getPositionX();
        virtual int getPositionY();

        virtual int getAD();
        virtual void setAD(int value);

        virtual int getDEF();
        virtual void setDEF(int value);

        virtual int getHP();
        virtual void setHP(int hp);

        virtual void setStats(int ad, int def, int hp);
        virtual void getStats();


        virtual void setName(std::string nick);
        virtual std::string getName();

        virtual void Update();
        virtual void Render();
        virtual bool checkAlive();
};

#endif // ENTITIES_H
