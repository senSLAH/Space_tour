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

Unit Enemy::get_position()
{
    return unit;
}

Unit Enemy::set_rand_position_on_the_screen()
{
    Unit position;
    position.position_x = rand() % 960 + 160;
    position.position_y = rand() % 540;
    return position;
}

bool Enemy::need_or_not_move_enemy()
{
    return false;
}


