#ifndef SIERPINSKI_TRIANGLE_HPP
#define SIERPINSKI_TRIANGLE_HPP

#include "fractal.hpp"

class SierpinskiTriangle : public Fractal
{
private:
public:
    SierpinskiTriangle();
    void iterate();
    void draw(sf::RenderWindow & window) const;
};

#endif