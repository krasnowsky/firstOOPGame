//
// Created by wszystko_ok on 15.01.2021.
//

#include "Sword.h"

Sword::Sword(const char *fileName, int x, int y) : Items(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    PositionX = x;
    PositionY = y;
}

void Sword::UpdateItem(Player &player) {
    if(!isTaken) {
        srcRect.h = 32;
        srcRect.w = 32;
        srcRect.x = 0;
        srcRect.y = 0;

        destRect.x = PositionX;
        destRect.y = PositionY;
        destRect.w = srcRect.w * 2;
        destRect.h = srcRect.h * 2;

        int PlayerPosX = player.getPositionX();
        int PlayerPosY = player.getPositionY();
        int PlayerAD = player.getAD();

        int ItemPosX = this->PositionX;
        int ItemPosY = this->PositionY;

        if (abs(PlayerPosX - ItemPosX) < 30 && abs(PlayerPosY - ItemPosY) < 30) {
            isTaken = true;
            objTexture = TextureManager::LoadTexture("blank");
            player.setAD(PlayerAD + attrDmg);
            std::cout << player.getName() << " (" << player.getAD() << " AD) increased AD by " << attrDmg << std::endl;
        }
    }
}

void Sword::RenderItem() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}
