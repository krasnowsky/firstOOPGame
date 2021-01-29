#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

class Entity;
class Item;
class Player;
class Slime;
class Snorlax;
class Dragon;
class Heal;
class Sword;
class Shield;
class Map;

class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() const{ return isRunning; }

        static SDL_Renderer* renderer;
        static SDL_Event event;
    private:
        std::shared_ptr<Player> player;
        std::shared_ptr<Slime> slime;
        std::shared_ptr<Snorlax> snorlax;
        std::shared_ptr<Dragon> dragon;
        std::shared_ptr<Heal> potion;
        std::shared_ptr<Sword> sword;
        std::shared_ptr<Shield> shield;
        std::shared_ptr<Map> map;

        std::vector<std::shared_ptr<Entity>> entities;
        std::vector<std::shared_ptr<Item>> items;

        bool isRunning{};

        SDL_Window *window{};
};

#endif // GAME_H
