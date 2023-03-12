#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Player.hpp"

void Player::event_handler(SDL_Keycode key, Uint32 event_type)
{
    bool pressed = event_type == SDL_KEYDOWN;
    switch (key)
    {
    case SDLK_q:
        setKey(0, pressed);
        break;
    case SDLK_d:
        setKey(1, pressed);
        break;
    case SDLK_z:
        setKey(2, pressed);
        break;
    case SDLK_s:
        setKey(3, pressed);
        break;

    default:
        break;
    }
}

void Player::update()
{
    if (getKey(0))
        move(-getSpeed(), 0);
    if (getKey(1))
        move(getSpeed(), 0);
    if (getKey(2))
        move(0, -getSpeed());
    if (getKey(3))
        move(0, getSpeed());
}

void Player::setKey(int key, bool pressed)
{
    keys[key] = pressed;
}

bool Player::getKey(int key)
{
    return keys[key];
}

float Player::getSpeed()
{
    return speed;
}

void Player::setSpeed(float speed_)
{
    speed = speed_;
}