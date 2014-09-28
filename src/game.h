#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "leapread.h"
#include "worm.h"


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

        // Game objects
        Worm worm;
};

#endif
