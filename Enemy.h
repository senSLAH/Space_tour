#ifndef SPACETOUR__ENEMY_H
#define SPACETOUR__ENEMY_H

#include <SFML/Graphics.hpp>



enum GameMode: int {NORMAL, HERO, GOD};

struct Position
{
    int position_x;
    int position_y;
};

class Enemy {
    int health;
    int speed;
    int attack;
    sf::Texture enemy_texture;
    sf::Sprite enemy_sprite;
    Position unit;

public:
    explicit Enemy(GameMode mode);
    void hit(int h);
    void attack_animations(sf::RenderWindow &win);
    void set_health(int h);
    void set_rand_position();
    Position set_rand_position_on_the_screen();
    void set_position(int pos_x, int pos_y, std::string str = "increase");
    Position get_position() const;
    int get_health() const;
    int get_attack() const;

    void draw_enemy(sf::RenderWindow &win);
};



#endif
