#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

#include "OpenSpace.h"
#include "ScreenController.h"
#include "Falcon_9.h"
#include "Enemies.h"
#include "Enemy.h"

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Tour");
    sf::Clock clock;

    Falcon_9 falcon;
    Enemies enemies(NORMAL);
    OpenSpace space(enemies);

    ScreenController ctrl(space, falcon, enemies, window);


    window.setFramerateLimit(30);

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
                space.key_press(event, true);
                falcon.key_press(event, true);
            }
            if (event.type == sf::Event::KeyReleased)
            {
                space.key_press(event, false);
                falcon.key_press(event, false);
            }
        }
        window.clear(sf::Color::Black);
        ctrl.draw();
        window.display();
    }
    return 0;
}