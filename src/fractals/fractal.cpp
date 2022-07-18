#include "fractal.hpp"
#include <string>

std::string Fractal::name() const
{
    return _name;
}

int Fractal::iteration() const
{
    return _iteration;
}