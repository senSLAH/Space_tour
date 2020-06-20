#ifndef SPACETOUR__ENEMIES_H
#define SPACETOUR__ENEMIES_H

#include <vector>
#include "Enemy.h"



class Enemies : public Enemy{
    std::vector<Enemy> enemy;
    sf::RenderWindow &window;

public:
    Enemies(GameMode mode, sf::RenderWindow &win);
    void add_enemy();
    void remove_enemy(int &i);
    void display_enemys();

};



#endif
