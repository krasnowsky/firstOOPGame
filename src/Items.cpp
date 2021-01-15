#include <Items.h>

Items::Items(const char *fileName, int x, int y) {
    objTexture = TextureManager::LoadTexture(fileName);
    PositionX = x;
    PositionY = y;
}

void Items::UpdateItem() {

}

void Items::RenderItem() {

}

