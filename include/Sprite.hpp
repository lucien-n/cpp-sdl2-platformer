#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite
{
public:
    Sprite(float x, float y, SDL_Texture *texture);
    float getX();
    float getY();
    void setX(float x_);
    void setY(float y_);
    SDL_Rect getRect();
    SDL_Texture *getTexture();
    void draw();

private:
    float x, y;
    SDL_Rect rect;
    SDL_Texture *texture;
};