#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.hpp"

class Entity : public Sprite
{
public:
    using Sprite::Sprite;
    void move(float x, float y);
};