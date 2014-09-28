#include "worm.h"

const sf::Color Worm::wormColor(255, 165, 140);

Worm::Worm():
    wormBody(sf::Quads, wormWidth)
{
    for (unsigned i = 0, x = 0; i < wormWidth; i += 4, x += 2)
    {
        wormBody[i].position = sf::Vector2f(x * segmentWidth, 200);
        wormBody[i + 1].position = sf::Vector2f(x * segmentWidth, 100);
        wormBody[i + 2].position = sf::Vector2f(x * segmentWidth + 100, 100);
        wormBody[i + 3].position = sf::Vector2f(x * segmentWidth + 100, 200);
        for (int count = 0; count < 4; ++count)
            wormBody[i + count].color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }

    collided = false;
}

void Worm::setPosition(const sf::Vector2f& pos, float dt)
{
    wormBody[wormWidth - 2].position = sf::Vector2f(pos.x + (wormWidth / 2) * segmentWidth, pos.y + 100);
    wormBody[wormWidth - 1].position = sf::Vector2f(pos.x + (wormWidth / 2) * segmentWidth, pos.y);
    position.x = wormBody[wormWidth - 2].position.x;
    position.y = wormBody[wormWidth - 2].position.y;

    const float threshold = 1.0f / 16.0f;
    for (int i = wormWidth - 6, x = wormWidth / 2; i >= 0; i -= 4, x -= 2)
    {
        float posDiff = wormBody[i + 5].position.y - wormBody[i + 1].position.y;
        wormBody[i + 1].position = sf::Vector2f(pos.x + x * segmentWidth, wormBody[i + 1].position.y + ((posDiff * dt) / threshold));
        wormBody[i + 2].position = wormBody[i + 1].position;

        posDiff = wormBody[i + 4].position.y - wormBody[i].position.y;
        wormBody[i].position = sf::Vector2f(pos.x + x * segmentWidth, wormBody[i].position.y + ((posDiff * dt) / threshold ));
        wormBody[i + 3].position = wormBody[i].position;
    }

    wormBody[0].position = wormBody[3].position;
    wormBody[1].position = wormBody[2].position;
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
