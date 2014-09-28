#ifndef LEVEL_H
#define LEVEL_H
#include <time.h>

class Level
{
    public:
        Level();
        virtual ~Level();
    protected:
    private:
        sf::Vector2f rockpos;
        sf::Vector2f foodpos;
        void genLevel();
        void genScene();
        sf::Vector2f spawnRock();
        sf::Vector2f spawnFood();
};

#endif // LEVEL_H
