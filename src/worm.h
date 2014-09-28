#ifndef WORM_H
#define WORM_H

#include <vector>
#include <SFML/Graphics.hpp>
class Worm : public sf::Drawable
{
    public:
        Worm();
        void setPosition(sf::Vector2f position);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::VertexArray wormBody;
        bool collided;

        static const unsigned wormWidth = 10 * 3;

        //int bodySize;
};

#endif
