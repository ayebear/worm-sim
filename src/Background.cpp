#include "Background.h"

Background::Background()
{
    quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(0, 0);
    quad[1].position = sf::Vector2f(WindowSize::window_width, 0);
    quad[3].position = sf::Vector2f(WindowSize::window_width, WindowSize::window_height);
    quad[4].position = sf::Vector2f(0, WindowSize::window_height);

    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(200, 0);
    quad[2].texCoords = sf::Vector2f(200, 400);
    quad[3].texCoords = sf::Vector2f(0, 400);
}

Background::~Background()
{
    //dtor
}
