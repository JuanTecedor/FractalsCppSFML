#ifndef MENGER_HPP
#define MENGER_HPP

#include "fractal.hpp"

class Menger : public Fractal
{
private:
public:
    void iterate();
    void draw(sf::RenderWindow & window) const;
};

#endif