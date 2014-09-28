#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background
{
    public:
        Background();
        virtual ~Background();
    protected:
    private:
        sf::PrimitiveType quad;
        sf::Transform state;
};

#endif // BACKGROUND_H
