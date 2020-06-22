#ifndef SPACETOUR__ENEMIES_H
#define SPACETOUR__ENEMIES_H

#include <vector>
#include "Enemy.h"



class Enemies : public Enemy{
    std::vector<Enemy> enemy;
    GameMode mode;
    int last_pos_x;
    int last_pos_y;
    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock cool_dawn_attack;


public:
    Enemies(GameMode m);
    void move_back_to_screen(int idx);

    void set_position(int n, int pos_x, int pos_y);
    int get_enemies_count() const;
    Enemy get_enemy(int idx);
    void add_enemy();
    void remove_enemy(int &idx);
    int attack(sf::RenderWindow &win);

    void draw_enemys(sf::RenderWindow &win);

};



#endif
