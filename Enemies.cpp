#include <iostream>
#include "Enemies.h"

Enemies::Enemies(GameMode m) :Enemy(m)
{
    int speed = 10;
    mode = m;
}

int Enemies::get_enemies_count() const
{
    return enemy.size();
}

void Enemies::set_position(int n, int pos_x, int pos_y)
{
    enemy[n].set_position(pos_x,pos_y);
}

Enemy Enemies::get_enemy(int idx)
{
    return enemy[idx];
}

//void Enemies::check_health(int idx)
//{
//    if (enemy[idx].get_health() <= 0)
//        remove_enemy(idx);
//}

void Enemies::add_enemy()
{
    Enemy e(mode);
    e.set_rand_position();
    enemy.push_back(e);
}

void Enemies::remove_enemy(int &idx)
{
    enemy[idx].hit(1);
    if (enemy[idx].get_health() <= 0)
    {
        enemy.erase(enemy.begin() + idx);
        add_enemy();
    }

}

void Enemies::draw_enemys(sf::RenderWindow &win)
{
    for (int i = 0; i < enemy.size(); ++i)
    {
        enemy[i].draw_enemy(win);
    }
}






