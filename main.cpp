#include <SFML/Graphics.hpp>
#include <iostream>

#include "OpenSpace.h"
#include "ScreenController.h"
#include "Falcon_9.h"

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Tour");

    OpenSpace space;
    ScreenController ctrl(space);
    Falcon_9 falcon;



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                ctrl.handleEvent(event);
            }
        }
        window.clear(sf::Color::Black);
        falcon.draw_falcon(window);
        //наисовать звёзды
        space.set_star_position();
        space.draw_star(window);

        window.display();
    }

    return 0;
}