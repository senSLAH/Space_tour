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
    sf::Clock clock2;
    sf::Time current_time;

public:
    Enemies(GameMode m);
    void add_enemy();
    void remove_enemy(int &idx);
    void move_back_to_screen(int idx);
    void check_health(int idx);
    void set_position(int n, int pos_x, int pos_y);
    void move_enemies();
    int get_enemies_count() const;
    Enemy get_enemy(int idx);
    void draw_enemys(sf::RenderWindow &win);

};



#endif
