#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>
#include <SFML/Graphics.hpp>
#include <deque>
#include "spriteloader.h"
class Level: public sf::Drawable
{
    public:
        Level();
        virtual ~Level();
        sf::Vector2f getRockPos();
        sf::Vector2f getFoodPos();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void genLevel(float);
    protected:
    private:
        sf::Vector2f rockpos;
        sf::Vector2f foodpos;
        SpriteLoader sprites;
        void genScene();
        void spawnRock(float);
        void spawnFood(float);
        void reapObjects();
        bool makerock;
        bool makefood;
        std::deque<sf::Sprite> rocks;
        std::deque<sf::Sprite> foods;
        sf::Sprite background;
        sf::Texture bg;
        sf::Texture r;
        sf::Texture f;

};

#endif // LEVEL_H
