#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>
#include <SFML/Graphics.hpp>
#include <deque>
//#include "TileMap.cpp"
#include "worm.h"

class Level: public sf::Drawable , public sf::Transformable
{
    public:
        Level();
        virtual ~Level();
        void updateObjects(float currentX, Worm& worm);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void genLevel(float, float);

    private:
        enum ObjectTypes
        {
            Rock = 0,
            Food
        };

        struct Object
        {
            int type;
            sf::Sprite sprite;
        };

        void genScene();
        void spawnRock(float, float);
        void spawnFood(float, float);
        void reapObjects();
        void gameOver();

        std::deque<Object> objects; // Rocks/food/etc.
        std::vector<sf::Sprite> backgrounds;
        sf::Texture bgTexture;
        sf::Texture r;
        sf::Texture f;

        int score;
        sf::Font font;
        sf::Text scoreCounter;

        sf::View uiView;
};

#endif // LEVEL_H
