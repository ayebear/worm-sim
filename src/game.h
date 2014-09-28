#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "leapread.h"
#include "worm.h"
#include "spriteloader.h"

class Game
{
    public:
        Game();
        ~Game();
        void start();

    private:
        void handleInput();
        void update(float dt);
        void draw();

        SampleListener listener;
        Controller controller;
        sf::RenderWindow window;
        sf::View view;
        SpriteLoader sprites;
        static const float scrollSpeed;
        // Game objects
        Worm worm;
        float currentX;
};

#endif
