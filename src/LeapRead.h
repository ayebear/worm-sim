#ifndef LEAPREAD_H
#define LEAPREAD_H

#include "Leap.h"
#include <SFML/Graphics.hpp>
#include <mutex>
using namespace Leap;

class SampleListener : public Listener
{
public:
    virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);
    virtual void onDeviceChange(const Controller&);
    virtual void onServiceConnect(const Controller&);
    virtual void onServiceDisconnect(const Controller&);

    sf::Vector2f getAveragePosition() const;
private:
    mutable std::mutex mu;
    sf::Vector2f position;
};

#endif
