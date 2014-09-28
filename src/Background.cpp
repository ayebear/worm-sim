#include "Background.h"
#include <SFML/Graphics.hpp>
#include "windowsize.h"

Background::Background()
{
    vertices.setPrimitiveType(sf::Quads, 4);
    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(WindowSize::window_width, 0);
    vertices[3].position = sf::Vector2f(WindowSize::window_width, WindowSize::window_height);
    vertices[4].position = sf::Vector2f(0, WindowSize::window_height);

    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(200, 0);
    vertices[2].texCoords = sf::Vector2f(200, 400);
    vertices[3].texCoords = sf::Vector2f(0, 400);
}

Background::~Background()
{
    //dtor
}
