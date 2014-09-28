#include "Level.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Level::Level()
{
    srand(time(NULL));
    if (!bg.loadFromFile("data/dirt.png") || !f.loadFromFile("data/food.png") || !r.loadFromFile("data/rock.png"))
    { std::cout<< "Error Loading" << std::endl;}
    background.setTexture(bg);
    rock.setTexture(r);
    food.setTexture(f);
}

Level::~Level()
{
    //dtor
}

void Level::genLevel()
{

    genScene();
}

sf::Vector2f Level::getFoodPos()
{
    return this->foodpos;
}

sf::Vector2f Level::getRockPos()
{
    return this->rockpos;
}

void Level::genScene()
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

void Level::spawnRock()
{
    rockpos.y = rand() % 100; // Find out what good max is
}

void Level::spawnFood()
{
    if(rockpos.y == (foodpos.y = rand() % 100))// run again if values are the same
    {
        spawnFood();
    }
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(background);
}


