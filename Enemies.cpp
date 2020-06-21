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

void Enemies::move_back_to_screen(int idx)
{
    int new_pos_x = set_rand_position_on_the_screen().position_x;
    int new_pos_y = set_rand_position_on_the_screen().position_y;

    sf::Time time = clock.getElapsedTime();
    if (time.asMicroseconds() > 0.4)
    {
        last_pos_x = enemy[idx].get_position().position_x;
        last_pos_y = enemy[idx].get_position().position_y;
        clock.restart();
    }
    sf::Time time1 = clock1.getElapsedTime();
    if (time1.asMicroseconds() > 0.1)
    {
        if (new_pos_x < last_pos_x)
            last_pos_x -= 5;
        if (new_pos_x > last_pos_x)
            last_pos_x += 5;
        if (new_pos_y < last_pos_y)
            last_pos_y -= 5;
        if (new_pos_y > last_pos_y)
            last_pos_y += 5;
            enemy[idx].set_position(last_pos_x, last_pos_y, "equel");
            clock1.restart();
    }
}

//void Enemies::move_enemies()
//{
//    for (int i = 0; i < enemy.size(); ++i)
//    {
//        Unit new_pos = set_rand_position_on_the_screen();
//        Unit pos_now = enemy[i].get_position();
//
//        sf::Time time2 = clock2.getElapsedTime();
//        if (time2.asSeconds() > 0.5)
//        {
//        while (new_pos.position_x != pos_now.position_x &&
//                new_pos.position_y != pos_now.position_y)
//        {
//            sf::Time time1 = clock1.getElapsedTime();
//            if (time1.asSeconds() > 0.5) {
//                if (pos_now.position_x < new_pos.position_x)
//                    ++pos_now.position_x;
//                if (pos_now.position_x > new_pos.position_x)
//                    --pos_now.position_x;
//                if (pos_now.position_y < new_pos.position_y)
//                    ++pos_now.position_y;
//                if (pos_now.position_y > new_pos.position_y)
//                    --pos_now.position_x;
//                enemy[i].set_position(pos_now.position_x, pos_now.position_y, "equel");
//                clock1.restart();
//            }
//        }
//        }
//    }
//}






