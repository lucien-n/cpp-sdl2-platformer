#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

void Entity::move(float x, float y)
{
    setX(getX() + x);
    setY(getY() + y);
}