#include "Enemies.h"

Enemies::Enemies(GameMode m) :Enemy(m)
{
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

void Enemies::add_enemy(GameMode m)
{
    Enemy e(m);
    e.set_rand_position();
    enemy.push_back(e);
}

int Enemies::remove_enemy(int &idx, GameMode m)
{
    enemy[idx].hit(1);
    if (enemy[idx].get_health() <= 0)
    {
        enemy.erase(enemy.begin() + idx);
        add_enemy(m);
        return 1;
    }
    return 0;
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
    sf::Time time1 = clock1.getElapsedTime();
    if (time.asMicroseconds() > 0.4)
    {
        last_pos_x = enemy[idx].get_position().position_x;
        last_pos_y = enemy[idx].get_position().position_y;
        clock.restart();
    }
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

int Enemies::attack(sf::RenderWindow &win)
{
    int en = rand() % enemy.size();
    sf::Time cool_dawn = cool_dawn_attack.getElapsedTime();

    if (cool_dawn.asSeconds() > 5)
    {
        cool_dawn_attack.restart();
        enemy[en].attack_animations(win);
        return enemy[en].get_attack();
    }
    return 0;
}

void Enemies::reset_enemies()
{
    enemy.clear();
}

void Enemies::restart_clock()
{
    clock.restart();
    clock1.restart();
    cool_dawn_attack.restart();
}









