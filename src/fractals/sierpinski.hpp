#ifndef SIERPINSKI_HPP
#define SIERPINSKI_HPP

#include "fractal.hpp"

class Sierpinski : public Fractal
{
private:
public:
    Sierpinski();
    void draw(sf::RenderWindow & window) const override;
};

#endif