#include "Level.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "windowsize.h"

Level::Level()
{
    srand(time(NULL));
    if (!bg.loadFromFile("data/dirt.png") || !f.loadFromFile("data/food.png") || !r.loadFromFile("data/rock.png"))
    { std::cout<< "Error Loading" << std::endl;}
    background.setTexture(bg);
    rocks.push_front(sf::Sprite()); // adds rock sprite to list
    rocks.front().setTexture(r);
    foods.push_front(sf::Sprite()); // adds food sprite to list
    foods.front().setTexture(f);
}

Level::~Level()
{
    while(!rocks.empty())
    {
        rocks.pop_front();
    }
    while(!foods.empty())
    {
        foods.pop_front();
    }
}

void Level::genLevel(float currentX)
{
    spawnRock(currentX);
    spawnFood(currentX);
}

sf::Vector2f Level::getFoodPos()
{
    return this->foodpos;
}

sf::Vector2f Level::getRockPos()
{
    return this->rockpos;
}

void Level::spawnRock(float currentX)
{
    if((rand() % 100 ) <33) // chance to spawn rock 33%
    {
        rocks.push_front(sf::Sprite()); // adds rock sprite to list
        rocks.front().setTexture(r);
        rocks.front().setPosition(currentX, rand() % WindowSize::window_height); // Find out what good max is
    }
}

void Level::spawnFood(float currentX)
{
    if((rand() % 100) < 33) //chance to spawn food
    {
        foods.push_front(sf::Sprite()); // adds food sprite to list
        foods.front().setTexture(f);
        foods.front().setPosition(currentX, rand() % WindowSize::window_height);// run again if values are the same
    }
}

void Level::reapObjects()
{
    //if(outside of vision)
    //rocks.pop_back();
    //food.pop_back();

}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(background);
    for(auto &rock : rocks)
    {
        target.draw(rock);
    }
    for(auto &food : foods)
    {
        target.draw(food);
    }

}


