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

    left_laser = false;
    up_laser = false;
    right_laser = false;
    down_laser = false;
    laser_bool = false;
    right_or_left_laser = true;

    sprite_cabine.setPosition(0, 0);
    sprite_cabine.setTexture(cabine_texture);
    sprite_cabine.setRotation(2);
    sprite_cabine.setScale(1, 1.05);
    sprite_cabine.setPosition(0, -40);

    scope_pos_x = 640;
    scope_pos_y = 360;

    sprite_scope.setTexture(scope_texture);
    sprite_scope.setPosition(scope_pos_x, scope_pos_y);


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

void Falcon_9::lasers(sf::RenderWindow &win)
{
    sf::VertexArray laser1(sf::Quads,4);
    sf::VertexArray laser2(sf::Triangles,3);

    laser1[0].position = sf::Vector2f (339,541);
    laser1[1].position = sf::Vector2f (433,541);
    laser1[2].position = sf::Vector2f (444,575);
    laser1[3].position = sf::Vector2f (scope_pos_x+40,scope_pos_y+40);
    laser1[0].color = sf::Color::Green;
    laser1[1].color = sf::Color::Green;
    laser1[2].color = sf::Color::Green;
    laser1[3].color = sf::Color::Red;

    laser2[0].position = sf::Vector2f (945,515);
    laser2[1].position = sf::Vector2f (950,510);
    laser2[2].position = sf::Vector2f (scope_pos_x + 40,scope_pos_y + 40);
    laser2[0].color = sf::Color::Red;
    laser2[1].color = sf::Color::Red;
    laser2[2].color = sf::Color(137, 19, 145);

    if (laser_bool)
    {
        if (right_or_left_laser)
        {
            win.draw(laser1);
        }
        else
        {
            win.draw(laser2);
        }
        (right_or_left_laser)? right_or_left_laser = false : right_or_left_laser = true;
    }
}

void Falcon_9::set_laser_pos()
{
    if (left_laser)
        scope_pos_x -= 5;
    if (up_laser)
        scope_pos_y -= 5;
    if (right_laser)
        scope_pos_x += 5;
    if (down_laser)
        scope_pos_y += 5;
    else
        return_laser();

    sprite_scope.setPosition(scope_pos_x, scope_pos_y);
}

void Falcon_9::key_press(sf::Event &e, bool set)
{
    int key = e.key.code;
    std::cout << key;
    switch (key)
    {
        case 71:
            left_laser = set;
            break;
        case 73:
            up_laser = set;
            break;
        case 72:
            right_laser = set;
            break;
        case 74:
            down_laser = set;
            break;
        case 57:
            laser_bool = set;
    }
}

void Falcon_9::return_laser()
{
    if (!(left_laser || up_laser || right_laser || down_laser))
    {
        if (scope_pos_x > 640)
            scope_pos_x -= 3;
        if (scope_pos_x < 640)
            scope_pos_x += 3;
        if (scope_pos_y > 360)
            scope_pos_y -= 3;
        if (scope_pos_y < 360)
            scope_pos_y += 3;
    }
}


