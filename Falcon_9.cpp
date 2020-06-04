#include <iostream>
#include "Falcon_9.h"


Falcon_9::Falcon_9()
{
    if (!cabine_texture.loadFromFile("../IMG/cabine1.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    cabine.setTexture(cabine_texture);
    cabine.setRotation(2);
    cabine.setScale(1, 1.05);
    cabine.setPosition(0, -40);

    speed = 5;
    scope = sf::RectangleShape(sf::Vector2f(20, 20));
    scope.setFillColor(sf::Color::Red);
    scope.setPosition(10,10);
}

void Falcon_9::draw_falcon(sf::RenderWindow &win)
{
    win.draw(cabine);
    win.draw(scope);
}

int Falcon_9::get_speed()
{
    return speed;
}
