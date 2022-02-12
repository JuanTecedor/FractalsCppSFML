#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include <SFML/Graphics.hpp>

class Fractal
{
protected:
    int _iteration;
    std::string _name;
public:
    Fractal();
    virtual void iterate() = 0;
    virtual void draw(sf::RenderWindow & window) const = 0;
    std::string name() const;
    int iteration() const;
};

#endif