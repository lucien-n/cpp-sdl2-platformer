#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Tile.hpp"
#include "Sprite.hpp"

class RenderWindow
{
public:
    RenderWindow(const char *title, int width, int height, int scale);
    int scale;
    SDL_Texture *loadTexture(const char *filePath);
    void cleanUp();
    void clear();
    // void render(SDL_Texture *texture, float x, float y);
    // void render(Entity &entity);
    // void render(Tile &tile);
    void render(Sprite &sprite);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};