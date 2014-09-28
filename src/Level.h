#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>
#include <SFML/System/Vector2.hpp>
class Level: public sf::Drawable
{
    public:
        Level();
        virtual ~Level();
        sf::Vector2f getRockPos();
        sf::Vector2f getFoodPos();
{)
    protected:
    private:
        sf::Vector2f rockpos;
        sf::Vector2f foodpos;
        void genLevel();
        void genScene();
        sf::Vector2f spawnRock();
        sf::Vector2f spawnFood();
        sf::Rect dirt;
        sf::Rect sky;
};

#endif // LEVEL_H
