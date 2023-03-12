#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.hpp"

Sprite::Sprite(float x, float y, SDL_Texture *texture) : x(x), y(y), texture(texture)
{
    rect.x = 0;
    rect.y = 0;
    int width;
    int height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    rect.w = width;
    rect.h = height;
}

float Sprite::getX()
{
    return x;
}

float Sprite::getY()
{
    return y;
}

void Sprite::setX(float x_)
{
    x = x_;
}

void Sprite::setY(float y_)
{
    y = y_;
}

SDL_Rect Sprite::getRect()
{
    return rect;
}

SDL_Texture *Sprite::getTexture()
{
    return texture;
}