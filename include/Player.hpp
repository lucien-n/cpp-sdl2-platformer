#pragma once

#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class Player : public Entity
{
public:
    using Entity::Entity;
    void event_handler(SDL_Keycode key, Uint32 event_type);
    void update();
    void setKey(int key, bool pressed);
    bool getKey(int key);
    float getSpeed();
    void setSpeed(float speed);

private:
    std::map<int, bool> keys = {{0, false}, {1, false}, {2, false}, {3, false}};
    float speed = 1;
};