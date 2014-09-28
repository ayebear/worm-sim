#ifndef LEAPREAD_H
#define LEAPREAD_H

#include "Leap.h"
#include <SFML/Graphics.hpp>
#include <mutex>
using namespace Leap;

class SampleListener : public Listener
{
public:
    virtual void onConnect(const Controller&);
    virtual void onFrame(const Controller&);
    sf::Vector2f getAveragePosition() const;

private:
    mutable std::mutex mu;
    sf::Vector2f position;
};

#endif
