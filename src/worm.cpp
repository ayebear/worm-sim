#include "worm.h"

Worm::Worm() :
    wormBody(sf::TrianglesStrip, 100)
{
    //ctor

    for(int i =0; i < 100; i++){
        if(i%2==0){
            wormBody[i].position = sf::Vector2f(i*10, 200);
            wormBody[i].color = sf::Color::Red;
        }
        else{
            wormBody[i].position = sf::Vector2f(i*10, 100);
            wormBody[i].color = sf::Color::Red;
        }
        //wormBody[i].texCoords = sf::Vector2f(100, 100);
    }

    collided = false;



}

void Worm::UpdateWorm(sf::Vector2f position){
    wormBody[0].position = position;
    for(int i = 0; i < 100; i++)
    {

    }
}

Worm::~Worm()
{
    //dtor
}

void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
// You can draw other high-level objects

// ... or use the low-level API
//states.texture = &m_texture;
target.draw(wormBody, states);

}
