#include "Level.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>
#include <stdlib.h>
#include "windowsize.h"
#include "events.h"
#include "gameevents.h"

Level::Level()
{
    srand(time(NULL));
    if (!f.loadFromFile("data/food.png") || !r.loadFromFile("data/rock.png") || !bgTexture.loadFromFile("data/dirt.png"))
    { std::cout<< "Error Loading" << std::endl;}
    //background.setTexture(bg);
    //objects.push_front(sf::Sprite()); // adds rock sprite to list
    //objects.front().setTexture(r);
    //objects.push_front(sf::Sprite()); // adds food sprite to list
    //objects.front().setTexture(f);
    backgrounds.resize(2);
    for (auto& bg: backgrounds)
        bg.setTexture(bgTexture);

    font.loadFromFile("data/fonts/Ubuntu-B.ttf");
    scoreCounter.setFont(font);
    scoreCounter.setString("Score: 0");
    scoreCounter.setCharacterSize(30);
    scoreCounter.setStyle(sf::Text::Bold);
    scoreCounter.setColor(sf::Color::White);

    uiView.reset(sf::FloatRect(0, 0, WindowSize::window_width, WindowSize::window_height));
}

Level::~Level()
{
    while(!objects.empty())
    {
        objects.pop_front();
    }
}

void Level::genLevel(float currentX, float dt)
{
    spawnRock(currentX, dt);
    spawnFood(currentX, dt);

    // Update background sprites
    if (backgrounds.back().getPosition().x < currentX - (WindowSize::window_width / 2))
    {
        backgrounds.front().setPosition(backgrounds.back().getPosition().x + WindowSize::window_width, 0);
        std::swap(backgrounds.front(), backgrounds.back());
    }
}

void Level::updateObjects(float currentX, Worm& worm)
{
    std::set<int> objectsToDelete;
    int counter = 0;
    for(auto & a : objects)
    {
        if(a.sprite.getPosition().x < currentX - WindowSize::window_width / 2 - 100)
        {
            objectsToDelete.insert(counter);
        }
        if (a.sprite.getGlobalBounds().intersects(worm.getAABB()))
        {
            if (a.type == Rock)
            {
                Events::send<GameOverEvent>();
                std::cout << "Game over!\n";
                exit(0);
            }
            else
            {
                // Food (increment score)
                std::cout << "Got food\n";
                objectsToDelete.insert(counter);
                ++score;
            }
        }
        ++counter;
    }
    for (auto& id: objectsToDelete)
        objects.erase(objects.begin() + id);

    scoreCounter.setString("Score: " + std::to_string(score));
}

void Level::spawnRock(float currentX, float dt)
{
    if((rand() % 100 ) < 3) // chance to spawn rock 33%
    {
        objects.push_front(Object{Rock, sf::Sprite()}); // adds rock sprite to list
        objects.front().sprite.setTexture(r);
        objects.front().sprite.setPosition(currentX + (WindowSize::window_width / 2), rand() % WindowSize::window_height); // Find out what good max is
    }
}

void Level::spawnFood(float currentX, float dt)
{
    if((rand() % 100) < 3) //chance to spawn food
    {
        objects.push_front(Object{Food, sf::Sprite()}); // adds food sprite to list
        objects.front().sprite.setTexture(f);
        objects.front().sprite.setPosition(currentX + (WindowSize::window_width / 2), rand() % WindowSize::window_height);// run again if values are the same
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
    for (auto& obj: objects)
        target.draw(obj.sprite);

    target.setView(uiView);
    target.draw(scoreCounter);

}

void Level::gameOver()
{
    return;// TODO display you loose!
}

//########################################################################################################
