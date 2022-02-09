#include <SFML/Graphics.hpp>
#include <memory>
#include "sierpinski.hpp"

int main()
{
    auto sz = std::min(sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().width);
    sf::RenderWindow window(sf::VideoMode(sz, sz), "Fractals!");
    std::unique_ptr<Fractal> fractal = std::make_unique<Sierpinski>();

    window.clear();
    fractal->draw(window);
    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                fractal->iterate();
                window.clear();
                fractal->draw(window);
                window.display();
            }    
        }
    }

    return 0;
}