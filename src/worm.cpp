#include "worm.h"

const sf::Color Worm::wormColor(255, 165, 140);

Worm::Worm():
    wormBody(sf::Quads, wormWidth)
{
    for (unsigned i = 0, x = 0; i < wormWidth; i += 4, x += 2)
    {
        wormBody[i].position = sf::Vector2f(x * 50, 200);
        wormBody[i + 1].position = sf::Vector2f(x * 50, 100);
        wormBody[i + 2].position = sf::Vector2f(x * 50 + 100, 100);
        wormBody[i + 3].position = sf::Vector2f(x * 50 + 100, 200);
        for (int count = 0; count < 4; ++count)
            wormBody[i + count].color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }

    collided = false;
}

void Worm::setPosition(const sf::Vector2f& pos, float dt)
{
//    position = pos;
//    sf::VertexArray tempPoints(sf::TrianglesStrip, wormWidth);
//    //wormBody[0].position = position;
//    for (unsigned i = 0; i < wormWidth - 3; ++i)
//    {
//        //wormBody[i].position = (wormBody[i].position + wormBody[i + 1].position);
//        tempPoints[i] = wormBody[i + 3];
//    }
//    wormBody = tempPoints;
//    wormBody[wormWidth - 3].position = sf::Vector2f(position.x, position.y);
//    wormBody[wormWidth - 3].color = wormColor;
//    wormBody[wormWidth - 2].position = sf::Vector2f(position.x, position.y + 100);
//    wormBody[wormWidth - 2].color = wormColor;
//    wormBody[wormWidth - 1].position = sf::Vector2f(position.x + 100, position.y + 100);
//    wormBody[wormWidth - 1].color = wormColor;

    wormBody[wormWidth - 2].position = sf::Vector2f(pos.x + wormWidth / 2, pos.y + 100);
    wormBody[wormWidth - 1].position = sf::Vector2f(pos.x + wormWidth / 2, pos.y);

    //const float threshold = 0.5;
    for (int i = wormWidth - 6, x = wormWidth / 2 - 3; i >= 4; i -= 4, x -= 2)
    {
        float posDiff = wormBody[i + 5].position.y - wormBody[i + 1].position.y;
        wormBody[i + 1].position = sf::Vector2f(pos.x + x * 10, posDiff * dt);
        wormBody[i + 2].position = wormBody[i + 1].position;

        posDiff = wormBody[i + 4].position.y - wormBody[i].position.y;
        wormBody[i].position = sf::Vector2f(pos.x + x * 10, posDiff * dt);
        wormBody[i + 3].position = wormBody[i].position;
    }
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
