#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Map.hpp"

bool RUNNING = false;
RenderWindow window = RenderWindow("SDL Platformer", 1280, 720, 4);

SDL_Texture *playerTexture = window.loadTexture("assets/textures/entity/player.png");
SDL_Texture *grassTexture = window.loadTexture("assets/textures/tile/grass.png");
SDL_Texture *stoneTexture = window.loadTexture("assets/textures/tile/stone.png");

Player player = Player(20, 20, playerTexture);
std::vector<Tile> tiles;

void event_handler()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            RUNNING = false;

        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            player.event_handler(event.key.keysym.sym, event.type);
    }
}

void update()
{
    player.update();
}

void draw()
{
    window.clear();

    for (Tile &tile : tiles)
    {
        window.render(tile);
    }

    window.render(player);

    window.display();
}

void run()
{
    while (RUNNING)
    {
        event_handler();
        update();
        draw();
    }
}

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL Video init failed. SDL Error: " << SDL_GetError() << std::endl;
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "SDL Image init failed. SDL Error: " << SDL_GetError() << std::endl;

    for (int y = 0; y < gameMap.size(); y++)
    {
        for (int x = 0; x < gameMap[y].size(); x++)
        {
            if (gameMap[y][x] == 1)
            {
                tiles.push_back(Tile(x * 16, y * 16, stoneTexture));
            }
        }
    }

    player.setSpeed(0.03);

    RUNNING = true;
    run();

    window.cleanUp();
    SDL_Quit();

    return 0;
}
