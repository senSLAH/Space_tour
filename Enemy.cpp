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
            break;
        case HERO:
            health = 15;
            speed = 6;
            break;
        case GOD:
            health = 20;
            speed = 7;
            break;
    }
}

void Enemy::hit(int h)
{
    health -= h;
}

void Enemy::set_speed(int s)
{
    health = s;
}

void Enemy::set_health(int h)
{
    health = h;
}

int Enemy::get_health() const
{
    return health;
}

int Enemy::get_speed() const
{
    return speed;
}

void Enemy::set_rand_position()
{
    unit.position_x = rand() % 1280;
    unit.position_y = rand() % 535;
    enemy_sprite.setPosition(unit.position_x, unit.position_y);
}

void Enemy::draw_enemy(sf::RenderWindow &win)
{
    enemy_sprite.setTexture(enemy_texture);
    win.draw(enemy_sprite);
}

void Enemy::set_position(int pos_x, int pos_y)
{
    unit.position_x += pos_x;
    unit.position_y += pos_y;
    enemy_sprite.setPosition(unit.position_x,unit.position_y);
}

Unit Enemy::get_position()
{
    return unit;
}


