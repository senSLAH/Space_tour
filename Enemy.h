#ifndef SPACETOUR__ENEMY_H
#define SPACETOUR__ENEMY_H

#include <SFML/Graphics.hpp>



enum GameMode: int {NORMAL, HERO, GOD};

class Enemy {
    int health;
    int speed;
    sf::Texture enemy_texture;
    sf::Sprite enemy;

public:
    explicit Enemy(GameMode mode);
    void hit(int &h);
    void setSpeed(int &s);
    int getHealth() const;
    int getSpeed() const;
    void draw_enemy(sf::RenderWindow &win) const;
};



#endif
