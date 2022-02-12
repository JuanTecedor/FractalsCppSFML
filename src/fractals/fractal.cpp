#include "fractal.hpp"
#include <string>

Fractal::Fractal()
    : _iteration{0}, _name{""}
{
}

std::string Fractal::name() const
{
    return _name;
}

int Fractal::iteration() const
{
    return _iteration;
}