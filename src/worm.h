#ifndef WORM_H
#define WORM_H

#include <vector>
#include <SFML/Graphics.hpp>
class Worm : public sf::Drawable
{
    public:
        Worm();
        virtual ~Worm();
        void UpdateWorm(sf::Vector2f position);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:

    private:
        sf::VertexArray wormBody;
        bool collided;

        //int bodySize;
};

#endif // WORM_H
