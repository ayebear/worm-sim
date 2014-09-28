#ifndef WORM_H
#define WORM_H

#include <vector>
#include <SFML/Graphics.hpp>
class Worm : public sf::Drawable
{
    public:
        Worm();
        void setPosition(const sf::Vector2f& position);
        const sf::Vector2f& getPosition() const;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::VertexArray wormBody;
        bool collided;
        sf::Vector2f position;
        static const unsigned wormWidth = 10 * 3;

        static const sf::Color wormColor;

        //int bodySize;
};

#endif
