#include "Heal.h"

Heal::Heal(const char *fileName, int x, int y) : Item(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    PositionX = x;
    PositionY = y;
}

void Heal::UpdateItem(Player &player) {
    if(!isTaken) {
        srcRect.h = 32;
        srcRect.w = 32;
        srcRect.x = 0;
        srcRect.y = 0;

        destRect.x = PositionX;
        destRect.y = PositionY;
        destRect.w = srcRect.w * 3;
        destRect.h = srcRect.h * 3;

        int PlayerPosX = player.getPositionX();
        int PlayerPosY = player.getPositionY();
        int PlayerHP = player.getHP();

        int ItemPosX = this->PositionX;
        int ItemPosY = this->PositionY;

        if (abs(PlayerPosX - ItemPosX) < 30 && abs(PlayerPosY - ItemPosY) < 30) {
            isTaken = true;
            objTexture = TextureManager::LoadTexture("blank");
            player.setHP(PlayerHP + 100);
            std::cout << player.getName() << " (" << player.getHP() << " HP) healed by 100 HP" << std::endl;
        }
    }
}

void Heal::RenderItem() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}

