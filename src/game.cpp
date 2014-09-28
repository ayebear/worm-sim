#include "game.h"

const float Game::scrollSpeed = 200;
const unsigned Game::window_width = 800;
const unsigned Game::window_height = 600;

Game::Game()
{
    // Have the sample listener receive events from the controller
    controller.addListener(listener);

    // Create a window
    window.create(sf::VideoMode(window_width, window_height), "Worm Simulator v0.0.2");
    view = window.getDefaultView();

}

Game::~Game()
{
    // Remove the sample listener when done
    controller.removeListener(listener);
}

void Game::start()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        handleInput();
        update(clock.restart().asSeconds());
        draw();
    }
}

void Game::handleInput()
{
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(float dt)
{
    //sprite.setPosition(listener.getAveragePosition());
    //worm.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition()));
    currentX += dt * scrollSpeed;
    auto pos = listener.getAveragePosition();
    pos.x = currentX;
    worm.setPosition(pos, dt);
    pos = worm.getPosition();
    view.setCenter(pos.x , 300);
    level.genLevel(pos.x);
    //view.move(10 * dt, 0);

}

void Game::draw()
{
    window.setView(view);

    // Clear screen
    window.clear();

    // Draw the sprite
    //window.draw(sprite);
    window.draw(level);
    window.draw(worm);

    // Update the window
    window.display();
}
