#include <iostream>
#include "Enemy.h"

Enemy::Enemy(GameMode mode)
{
    if (!enemy_texture.loadFromFile("../IMG/Red_enemy.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    enemy.setTexture(enemy_texture);
    enemy.setPosition(400,360);
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

void Enemy::hit(int &h)
{
    health -= h;
}

void Enemy::setSpeed(int &s)
{
    health = s;
}

int Enemy::getHealth() const
{
    return health;
}

int Enemy::getSpeed() const
{
    return speed;
}

void Enemy::draw_enemy(sf::RenderWindow &win) const
{
    win.draw(enemy);
}

