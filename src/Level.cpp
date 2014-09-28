#include "Level.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "windowsize.h"

Level::Level()
{
    srand(time(NULL));
    if (!f.loadFromFile("data/food.png") || !r.loadFromFile("data/rock.png"))
    { std::cout<< "Error Loading" << std::endl;}
    //background.setTexture(bg);
    rocks.push_front(sf::Sprite()); // adds rock sprite to list
    rocks.front().setTexture(r);
    foods.push_front(sf::Sprite()); // adds food sprite to list
    foods.front().setTexture(f);
    quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(0, 0);
    quad[1].position = sf::Vector2f(WindowSize::window_width, 0);
    quad[3].position = sf::Vector2f(WindowSize::window_width, WindowSize::window_height);
    quad[4].position = sf::Vector2f(0, WindowSize::window_height);

    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(200, 0);
    quad[2].texCoords = sf::Vector2f(200, 400);
    quad[3].texCoords = sf::Vector2f(0, 400);
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

sf::Vector2f Level::getRockPositions(float wormY)
{
    for(auto a : rocks)
    {
        if(a.GetPosition().y >= wormY - 10 || wormY + 10 <= a.GetPosition().y)
        {
            gameOver();
        }
    }
}

void Level::spawnRock(float currentX)
{
    if((rand() % 100 ) < 33) // chance to spawn rock 33%
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

void Level::gameOver()
{
    return;// TODO display you loose!
}

//########################################################################################################
