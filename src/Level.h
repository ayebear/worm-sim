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
        sf::Vector2f getRockPositions(float);
        sf::Vector2f getFoodPos();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void genLevel(float, float);

    private:
        void genScene();
        void spawnRock(float, float);
        void spawnFood(float, float);
        void reapObjects();
        void gameOver();

        std::deque<sf::Sprite> rocks;
        std::deque<sf::Sprite> foods;
        std::vector<sf::Sprite> backgrounds;
        sf::Texture bgTexture;
        sf::Texture r;
        sf::Texture f;

};

#endif // LEVEL_H
