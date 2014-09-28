#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>
#include <SFML/Graphics.hpp>
#include <deque>
#include "TileMap.cpp"
class Level: public sf::Drawable , public sf::Transformable
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
        void genScene();
        void spawnRock(float);
        void spawnFood(float);
        void reapObjects();
        void gameOver();
        std::deque<sf::Sprite> rocks;
        std::deque<sf::Sprite> foods;
        sf::Sprite background;
        sf::Texture bg;
        sf::Texture r;
        sf::Texture f;
        sf::VertexArray quad;

};

#endif // LEVEL_H
