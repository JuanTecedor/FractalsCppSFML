#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include <SFML/Graphics.hpp>

class Fractal
{
public:
    virtual ~Fractal() = default;
protected:
    int _iteration;
    std::string _name;
public:
    virtual void draw(sf::RenderWindow & window) const = 0;
    std::string name() const;
    int iteration() const;
    void iterate();
};

#endif