#include "Enemies.h"

Enemies::Enemies(GameMode m) :Enemy(m)
{
    int speed = 10;
    m = mode;
}

void Enemies::add_enemy()
{
    Enemy e(mode);
    e.set_rand_position();
    enemy.push_back(e);
}

void Enemies::remove_enemy(int &i)
{

}

void Enemies::draw_enemys(sf::RenderWindow &win)
{
    for (int i = 0; i < enemy.size(); ++i)
    {
        enemy[i].draw_enemy(win);
    }
}

int Enemies::get_enemies_count() const
{
    return enemy.size();
}

void Enemies::set_position(int n, int pos_x, int pos_y)
{
    enemy[n].set_position(pos_x,pos_y);
}




