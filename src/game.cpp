#include "game.h"

const float Game::scrollSpeed = 200;

Game::Game()
{
    // Have the sample listener receive events from the controller
    controller.addListener(listener);

    // Create a window
    window.create(sf::VideoMode(800, 600), "Worm Simulator v0.0.1");
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
    worm.setPosition(pos);
    view.setCenter(pos.x , 300);
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
