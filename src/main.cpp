#include <SFML/Graphics.hpp>
#include <memory>
#include "fractals/sierpinski.hpp"
#include "fractals/sierpinskiTriangle.hpp"

void reset(const Fractal * const fractal, sf::RenderWindow & window)
{
    window.clear();
    fractal->draw(window);
    window.display();
    window.setTitle(fractal->name());
}

int main()
{
    auto sz = std::min(sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().width);
    sf::RenderWindow window(sf::VideoMode(sz, sz), "Fractals!");
    std::unique_ptr<Fractal> fractal = std::make_unique<Sierpinski>();

    reset(fractal.get(), window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Num1)
                {
                    fractal = std::make_unique<Sierpinski>();
                    reset(fractal.get(), window);
                }
                else if(event.key.code == sf::Keyboard::Num2)
                {
                    fractal = std::make_unique<SierpinskiTriangle>();
                    reset(fractal.get(), window);
                }
                else if (event.key.code == sf::Keyboard::Space)
                {
                    fractal->iterate();
                    window.clear();
                    fractal->draw(window);
                    window.display();
                }  
                else if(event.key.code == sf::Keyboard::S)
                {
                    sf::Texture texture;
                    texture.create(sz, sz);
                    texture.update(window);
                    texture.copyToImage().saveToFile(fractal->name() + std::to_string(fractal->iteration()) + ".png");
                }  
            }
        }
    }

    return 0;
}