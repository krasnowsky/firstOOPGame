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

        float HP;
        float AD;
        float DEF;

        bool isAlive = true;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;

    public:
        Entities(const char* fileName, int x, int y);
        virtual ~Entities();


        virtual int getPositionX();
        virtual int getPositionY();

        virtual float getAD();
        virtual float getDEF();
        virtual float getHP();

        virtual void setStats(float ad, float def, float hp);
        virtual void getStats();
        virtual void setHP(float hp);


        virtual void movementX(int right);
        virtual void movementY(int up);

        virtual void setName(std::string nick);
        virtual std::string getName();

        virtual void Update();
        virtual void Render();
        virtual bool checkAlive();
};

#endif // ENTITIES_H
