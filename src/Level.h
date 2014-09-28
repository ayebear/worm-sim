#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>
#include <SFML/Graphics.hpp>
class Level: public sf::Drawable
{
    public:
        Level();
        virtual ~Level();
        sf::Vector2f getRockPos();
        sf::Vector2f getFoodPos();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
    private:
        sf::Vector2f rockpos;
        sf::Vector2f foodpos;
        void genLevel();
        void genScene();
        void spawnRock();
        void spawnFood();

};

#endif // LEVEL_H
