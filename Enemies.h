#ifndef SPACETOUR__ENEMIES_H
#define SPACETOUR__ENEMIES_H

#include <vector>
#include "Enemy.h"



class Enemies : public Enemy{
    std::vector<Enemy> enemy;

public:
    Enemies(GameMode mode);
    void add_enemy();
    void remove_enemy(int &i);
    void display_enemys(sf::RenderWindow &win);

};



#endif
