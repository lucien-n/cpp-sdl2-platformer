#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Tile.hpp"
#include "Sprite.hpp"

RenderWindow::RenderWindow(const char *title, int width, int height, int scale_) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "Window init failed. SDL Error: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    scale = scale_;
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath)
{
    SDL_Texture *texture = NULL;

    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == NULL)
        std::cout << "Texure load failed. SDL Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

// void RenderWindow::render(SDL_Texture *texture, float x, float y)
// {
//     SDL_Rect src;
//     src.x = 0;
//     src.y = 0;
//     src.w = 16;
//     src.h = 16;

//     SDL_Rect dest;
//     dest.x = x;
//     dest.y = y;
//     dest.w = 16 * scale;
//     dest.h = 16 * scale;

//     SDL_RenderCopy(renderer, texture, &src, &dest);
// }

// void RenderWindow::render(Entity &entity)
// {
//     SDL_Rect src = entity.getRect();

//     SDL_Rect dest;
//     dest.x = entity.getX() * scale;
//     dest.y = entity.getY() * scale;
//     dest.w = entity.getRect().w * scale;
//     dest.h = entity.getRect().h * scale;

//     SDL_RenderCopy(renderer, entity.getTexture(), &src, &dest);
// }

// void RenderWindow::render(Tile &tile)
// {
//     SDL_Rect src;
//     src.x = tile.getRect().x;
//     src.y = tile.getRect().y;
//     src.w = tile.getRect().w;
//     src.h = tile.getRect().h;

//     SDL_Rect dest;
//     dest.x = tile.getX();
//     dest.y = tile.getY();
//     dest.w = tile.getRect().w * scale;
//     dest.h = tile.getRect().h * scale;

//     SDL_RenderCopy(renderer, tile.getTexture(), &src, &dest);
// }

void RenderWindow::render(Sprite &sprite)
{
    SDL_Rect src = sprite.getRect();

    SDL_Rect dest;
    dest.x = sprite.getX() * scale;
    dest.y = sprite.getY() * scale;
    dest.w = sprite.getRect().w * scale;
    dest.h = sprite.getRect().h * scale;

    SDL_RenderCopy(renderer, sprite.getTexture(), &src, &dest);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}