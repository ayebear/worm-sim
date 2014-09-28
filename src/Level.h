#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>
#include <SFML/Graphics.hpp>
#include "spriteloader.h"
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
        SpriteLoader sprites;
        void genLevel();
        void genScene();
        void spawnRock();
        void spawnFood();
        sf::Sprite sprite;
        sf::Texture texture;

};

#endif // LEVEL_H
