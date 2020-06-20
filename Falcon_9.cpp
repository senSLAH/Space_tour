#include <iostream>
#include "Falcon_9.h"


Falcon_9::Falcon_9()
{
    if (!cabine_texture.loadFromFile("../IMG/cabine1.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!scope_texture.loadFromFile("../IMG/scope.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }


    sprite_cabine.setPosition(0, 0);
    sprite_cabine.setTexture(cabine_texture);
    sprite_cabine.setRotation(2);
    sprite_cabine.setScale(1, 1.05);
    sprite_cabine.setPosition(0, -40);



    sprite_scope.setTexture(scope_texture);
    sprite_scope.setPosition(640, 360);


    speed = 5;

}

void Falcon_9::draw_falcon(sf::RenderWindow &win) const
{
    win.draw(sprite_cabine);
    win.draw(sprite_scope);
}

int Falcon_9::get_speed()
{
    return speed;
}
