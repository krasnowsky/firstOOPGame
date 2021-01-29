#include <Shield.h>

Shield::Shield(const char *fileName, int x, int y) : Item(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    PositionX = x;
    PositionY = y;
}

void Shield::UpdateItem(Player &player) {
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
        int PlayerDEF = player.getDEF();

        int ItemPosX = this->PositionX;
        int ItemPosY = this->PositionY;

        if (abs(PlayerPosX - ItemPosX) < 30 && abs(PlayerPosY - ItemPosY) < 30) {
            isTaken = true;
            objTexture = TextureManager::LoadTexture("blank");
            player.setDEF(PlayerDEF + attrDef);
            std::cout << player.getName() << " (" << player.getDEF() << " DEF) increased DEF by " << attrDef << std::endl;
        }
    }
}

void Shield::RenderItem() {
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &destRect);
}

