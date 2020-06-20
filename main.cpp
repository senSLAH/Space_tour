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

    OpenSpace space;

    ScreenController ctrl(space);
    Falcon_9 falcon;
    Enemies enemies(NORMAL, window);

    int time;

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
            }
        }

        sf::Time time = clock.getElapsedTime();
        std::cout << time.asSeconds() << std::endl;


        //std::cout << ((float)clock()) / CLOCKS_PER_SEC << std::endl;
        //std::cout << space.get_star_count() << "\n";
        window.clear(sf::Color::Black);
        space.set_star_position();
        space.draw_star(window);
        enemies.draw_enemy(window);
        falcon.draw_falcon(window);

        window.display();
    }

    return 0;
}