#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background
{
    public:
        Background();
        virtual ~Background();
    protected:
    private:
        sf::VertexArray quad;
        sf::Transform state;
};

#endif // BACKGROUND_H
