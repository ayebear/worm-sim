#include <SFML/Graphics.hpp>
#include "LeapRead.h"
#include "worm.h"

int main()
{
    // Create a sample listener and controller
    SampleListener listener;
    Controller controller;

    // Have the sample listener receive events from the controller
    controller.addListener(listener);

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("data/wormlink.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

    Worm worm;
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Update
        sprite.setPosition(listener.getAveragePosition());
        worm.UpdateWorm(app.mapPixelToCoords(sf::Mouse::getPosition()));

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);
        app.draw(worm);

        // Update the window
        app.display();
    }

    // Remove the sample listener when done
    controller.removeListener(listener);

    return EXIT_SUCCESS;
}
