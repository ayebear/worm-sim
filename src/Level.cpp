#include "Level.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "windowsize.h"

Level::Level()
{
    srand(time(NULL));
    if (!f.loadFromFile("data/food.png") || !r.loadFromFile("data/rock.png") || !bgTexture.loadFromFile("data/dirt.png"))
    { std::cout<< "Error Loading" << std::endl;}
    //background.setTexture(bg);
    rocks.push_front(sf::Sprite()); // adds rock sprite to list
    rocks.front().setTexture(r);
    foods.push_front(sf::Sprite()); // adds food sprite to list
    foods.front().setTexture(f);
    backgrounds.resize(2);
    for (auto& bg: backgrounds)
        bg.setTexture(bgTexture);
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

void Level::genLevel(float currentX, float dt)
{
    spawnRock(currentX, dt);
    spawnFood(currentX, dt);

    // Update background sprites
    if (backgrounds.back().getPosition().x < currentX - (WindowSize::window_width / 2))
    {
        backgrounds.front().setPosition(currentX + (WindowSize::window_width / 2), 0);
        std::swap(backgrounds.front(), backgrounds.back());
    }
}

sf::Vector2f Level::getFoodPos()
{
    //return this->foodpos;
}

sf::Vector2f Level::getRockPositions(float wormY)
{
    for(auto a : rocks)
    {
        if(a.getPosition().y >= wormY - 10 || wormY + 10 <= a.getPosition().y)
        {
            gameOver();
        }
    }
}

void Level::spawnRock(float currentX, float dt)
{
    if((rand() % 100 ) < 3) // chance to spawn rock 33%
    {
        rocks.push_front(sf::Sprite()); // adds rock sprite to list
        rocks.front().setTexture(r);
        rocks.front().setPosition(currentX + (WindowSize::window_width / 2), rand() % WindowSize::window_height); // Find out what good max is
    }
}

void Level::spawnFood(float currentX, float dt)
{
    if((rand() % 100) < 3) //chance to spawn food
    {
        foods.push_front(sf::Sprite()); // adds food sprite to list
        foods.front().setTexture(f);
        foods.front().setPosition(currentX + (WindowSize::window_width / 2), rand() % WindowSize::window_height);// run again if values are the same
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
    for (auto& bg: backgrounds)
        target.draw(bg);
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
