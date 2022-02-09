#include <math.h>
#include "menger.hpp"

void Menger::iterate()
{
    _iteration++;
}

void Menger::draw(sf::RenderWindow & window) const
{
    const auto sz = sf::Vector2f
    {
        window.getSize().x / std::pow(3, _iteration),
        window.getSize().y / std::pow(3, _iteration)
    };

    auto cubeCountRow = std::pow(3, _iteration); // number of cubes in a row
    for(auto y = 0; y < cubeCountRow; y++)
    {
        for(auto x = 0; x < cubeCountRow; x++)
        {
            bool ok = true;
            auto xx = x, yy = y;
            while (xx > 0 || yy > 0)
            {
                if (xx % 3 == 1 && yy % 3 == 1)
                {
                    ok = false;
                    break;
                }
                xx /= 3;
                yy /= 3;
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