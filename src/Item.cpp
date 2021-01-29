#include <Item.h>

Item::Item(const char *fileName, int x, int y) {
    objTexture = TextureManager::LoadTexture(fileName);
    PositionX = x;
    PositionY = y;
}

void Item::UpdateItem() {

}

void Item::RenderItem() {

}

