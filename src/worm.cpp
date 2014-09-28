#include "worm.h"

const sf::Color Worm::wormColor(255, 165, 140);

Worm::Worm():
    wormBody(sf::TrianglesStrip, wormWidth)
{
    for (unsigned i = 0; i < wormWidth; ++i)
    {
        unsigned yPos = 100;
        if (i % 2 == 0)
            yPos = 200;
        wormBody[i].position = sf::Vector2f(i * 10, yPos);
        wormBody[i].color = wormColor;
    }

    collided = false;
}

void Worm::setPosition(const sf::Vector2f& pos)
{
    position = pos;
    sf::VertexArray tempPoints(sf::TrianglesStrip, wormWidth);
    //wormBody[0].position = position;
    for (unsigned i = 0; i < wormWidth - 3; ++i)
    {
        //wormBody[i].position = (wormBody[i].position + wormBody[i + 1].position);
        tempPoints[i] = wormBody[i + 3];
    }
    wormBody = tempPoints;
    wormBody[wormWidth - 3].position = sf::Vector2f(position.x, position.y);
    wormBody[wormWidth - 3].color = wormColor;
    wormBody[wormWidth - 2].position = sf::Vector2f(position.x, position.y + 100);
    wormBody[wormWidth - 2].color = wormColor;
    wormBody[wormWidth - 1].position = sf::Vector2f(position.x + 100, position.y + 100);
    wormBody[wormWidth - 1].color = wormColor;
}

const sf::Vector2f& Worm::getPosition() const
{
    return position;
}

void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //states.texture = &m_texture;
    target.draw(wormBody, states);
}
