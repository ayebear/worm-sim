#include "Level.h"

Level::Level()
{
    srand(time(NULL));

}

Level::~Level()
{
    //dtor
}

Level::genLevel()
{


}

sf::Vector2f Level::getFoodPos()
{
    return this->foodpos;
}

sf::Vector2f Level::getRockPos()
{
    return this->rockpos;
}

Level::genScene()
{
    if((rand() % 100 ) < 33) // chance to spawn rock 33%
    {
        spawnRock();
    }

    if((rand() % 100) < 33) //chance to spawn food
    {
        spawnFood();
    }

}

Level::spawnRock()
{
    this->rockpos = rand() % 100; // Find out what good max is
}

Level::spawnFood()
{
    if(this->rockpos == (this->foodpos = rand() % 100))// run again if values are the same
    {
        spawnFood();
    }
}

Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{


}


