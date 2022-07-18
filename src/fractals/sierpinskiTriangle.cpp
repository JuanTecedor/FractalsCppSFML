#include <math.h>
#include "sierpinskiTriangle.hpp"

SierpinskiTriangle::SierpinskiTriangle()
{
    _name = "SierpinskiTriangle";
    _iteration = 0;
}

void SierpinskiTriangle::iterate()
{
    _iteration++;
}

void SierpinskiTriangle::draw(sf::RenderWindow & window) const
{
    const auto sz = sf::Vector2f
    {
        static_cast<float>(window.getSize().x / std::pow(2, _iteration)),
        static_cast<float>(window.getSize().y / std::pow(2, _iteration))
    };

    auto cubeCountRow = std::pow(2, _iteration); // number of cubes in a row
    for(auto y = 0; y < cubeCountRow; y++)
    {
        for(auto x = 0; x < cubeCountRow; x++)
        {
            bool ok = true;
            auto xx = x, yy = y;
            while (xx > 0 || yy > 0)
            {
                if (xx % 2 == 1 && yy % 2 == 1)
                {
                    ok = false;
                    break;
                }
                xx /= 2;
                yy /= 2;
            }
            if(ok)
            {
                sf::RectangleShape rect(sz);
                rect.setPosition({x * sz.x, y * sz.y});
                window.draw(rect);
            }
        }
    }
}