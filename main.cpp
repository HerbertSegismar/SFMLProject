#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Vector Crafts", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Image icon;
    if (!icon.loadFromFile("vectorcrafts.png"))
    {
        return -1;
    }

    window.setIcon(icon);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }

            if (const auto* ev = event->getIf<sf::Event::KeyPressed>()){

                switch (ev->scancode)
                {
                case sf::Keyboard::Scan::Escape:
                    window.close();
                    break;

                case sf::Keyboard::Scan::Space:
                    window.close();
                    break;
                
                default:
                    break;
                }
            }

        }

        window.clear(sf::Color(34,5,54,255));
        window.draw(shape);
        window.display();
    }
    return 0;
}