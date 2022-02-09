#ifndef SIERPINSKI_HPP
#define SIERPINSKI_HPP

#include "fractal.hpp"

class Sierpinski : public Fractal
{
private:
public:
    void iterate();
    void draw(sf::RenderWindow & window) const;
};

#endif