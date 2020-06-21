#ifndef SPACETOUR__ENEMY_H
#define SPACETOUR__ENEMY_H

#include <SFML/Graphics.hpp>



enum GameMode: int {NORMAL, HERO, GOD};

struct Unit
{
    int position_x;
    int position_y;
};

class Enemy {
    int health;
    int speed;
    sf::Texture enemy_texture;
    sf::Sprite enemy_sprite;
    Unit unit;

public:
    explicit Enemy(GameMode mode);
    void hit(int h);
    void set_health(int h);
    void set_speed(int s);
    void set_rand_position();
    Unit set_rand_position_on_the_screen();
    void set_position(int pos_x, int pos_y, std::string str = "increase");
    Unit get_position();
    bool need_or_not_move_enemy();
    void draw_enemy(sf::RenderWindow &win);
    int get_health() const;
    int get_speed() const;
};



#endif
