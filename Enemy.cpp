#include <iostream>
#include "Enemy.h"

Enemy::Enemy(GameMode mode)
{
    if (!enemy_texture.loadFromFile("../IMG/Red_enemy.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    set_rand_position();

    switch (mode)
    {
        case NORMAL:
            health = 10;
            speed = 5;
            attack = 10;
            break;
        case HERO:
            health = 15;
            speed = 6;
            attack = 15;
            break;
        case GOD:
            health = 20;
            speed = 7;
            attack = 20;
            break;
    }
}

void Enemy::hit(int h)
{
    health -= h;
}

void Enemy::set_health(int h)
{
    health = h;
}

int Enemy::get_health() const
{
    return health;
}

void Enemy::set_rand_position()
{
    if(rand() % 2)
    {
        unit.position_x = -200;
    }
    else
    {
        unit.position_x = 1480;
    }
    if (rand() % 2)
    {
        unit.position_y = -100;
    }
    else
    {
        unit.position_y = 820;
    }

    enemy_sprite.setPosition(unit.position_x, unit.position_y);
}

void Enemy::draw_enemy(sf::RenderWindow &win)
{
    enemy_sprite.setTexture(enemy_texture);
    enemy_sprite.setPosition(unit.position_x,unit.position_y);
    win.draw(enemy_sprite);
}

void Enemy::set_position(int pos_x, int pos_y, std::string str)
{
    if (str == "equel")
    {
        unit.position_x = pos_x;
        unit.position_y = pos_y;
    }
    if (str == "increase")
    {
        unit.position_x += pos_x;
        unit.position_y += pos_y;
    }

    enemy_sprite.setPosition(unit.position_x,unit.position_y);
}

Position Enemy::get_position() const
{
    return unit;
}

Position Enemy::set_rand_position_on_the_screen()
{
    Position position;
    position.position_x = rand() % 960 + 160;
    position.position_y = rand() % 540;
    return position;
}

int Enemy::get_attack() const
{
    return attack;
}

void Enemy::attack_animations(sf::RenderWindow &win)
{
    sf::VertexArray laser1(sf::Triangles,3);
    sf::VertexArray laser2(sf::Triangles,3);
    int x_rand = rand() % 580 + 350;
    int y_rand = rand() % 440 + 100;

    laser1[0].position = sf::Vector2f (unit.position_x + 40,unit.position_y + 55);
    laser1[1].position = sf::Vector2f (unit.position_x + 54,unit.position_y + 65);
    laser1[2].position = sf::Vector2f (x_rand,y_rand);

    laser1[0].color = sf::Color::Red;
    laser1[1].color = sf::Color::Red;
    laser1[2].color = sf::Color(137, 19, 145);

    laser2[0].position = sf::Vector2f (unit.position_x + 120,unit.position_y + 51);
    laser2[1].position = sf::Vector2f (unit.position_x + 110,unit.position_y + 61);
    laser2[2].position = sf::Vector2f (x_rand,y_rand);

    laser2[0].color = sf::Color::Red;
    laser2[1].color = sf::Color::Red;
    laser2[2].color = sf::Color(137, 19, 145);

    win.draw(laser1);
    win.draw(laser2);

}



