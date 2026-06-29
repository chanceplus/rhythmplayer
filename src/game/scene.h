#pragma once

#include "game.h"

#ifndef GAME_SCENE
#define GAME_SCENE

class Scene
{
public:
    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};

#endif