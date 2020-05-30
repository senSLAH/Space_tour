#include "Falcon_9.h"

Falcon_9::Falcon_9()
{
    speed = 5;
    scope = sf::RectangleShape(sf::Vector2f(20, 20));
    scope.setFillColor(sf::Color::Red);
    scope.setPosition(10,10);
}

void Falcon_9::draw_falcon(sf::RenderWindow &win)
{
    win.draw(scope);
}

int Falcon_9::get_speed()
{
    return speed;
}
