#pragma once

#include <stack>

#include <SFML/Graphics.hpp>

#include "scene.h"

#ifndef GAME
#define GAME

class Game
{
public:
    std::stack<Scene*> scenes;

    sf::RenderWindow window;

    void pushScene(Scene* scene);
    void popScene();
    void changeScene(Scene* scene);
    Scene* peekScene();

    void gameLoop();

    Game();
    ~Game();
};

#endif