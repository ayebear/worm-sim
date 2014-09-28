#include "worm.h"

Worm::Worm():
    wormBody(sf::TrianglesStrip, wormWidth)
{
    for (unsigned i = 0; i < wormWidth; ++i)
    {
        unsigned yPos = 100;
        if (i % 2 == 0)
            yPos = 200;
        wormBody[i].position = sf::Vector2f(i * 10, yPos);
        wormBody[i].color = sf::Color(255, 165, 140);
    }

    collided = false;
}

void Worm::setPosition(sf::Vector2f position)
{
    wormBody[0].position = position;
    for (unsigned i = 0; i < wormWidth; ++i)
    {
        //wormBody[i]
    }
}

void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //states.texture = &m_texture;
    target.draw(wormBody, states);
}
