#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "leapread.h"
#include "worm.h"
#include "Level.h"

class Game
{
    public:
        Game();
        ~Game();
        void start();
        static const unsigned window_width;
        static const unsigned window_height;
        float currentX;
    private:
        void handleInput();
        void update(float dt);
        void draw();
        Level level;
        SampleListener listener;
        Controller controller;
        sf::RenderWindow window;
        sf::View view;
        static const float scrollSpeed;

        // Game objects
        Worm worm;

};

#endif
