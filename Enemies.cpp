#include "Enemies.h"

Enemies::Enemies(GameMode mode, sf::RenderWindow &win) : window(win), Enemy(mode)
{

    int speed = 10;

    for (int i = 0; i < 1; ++i)
    {
        Enemy enemy_n(mode);
        enemy.push_back(enemy_n);
    }
}

void Enemies::display_enemys()
{
    for (int i = 0; i < enemy.size(); ++i)
    {
        enemy[i].draw_enemy(window);
    }
}
