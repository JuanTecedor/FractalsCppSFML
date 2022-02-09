#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include <SFML/Graphics.hpp>

class Fractal
{
protected:
    int _iteration;
public:
    Fractal();
    virtual void iterate() = 0;
    virtual void draw(sf::RenderWindow & window) const = 0;
};

#endif