#ifndef SPACETOUR__FALCON_9_H
#define SPACETOUR__FALCON_9_H
#include <SFML/Graphics.hpp>


class Falcon_9 {
    int speed;
    sf::Texture scope_texture;
    sf::Texture cabine_texture;
    sf::Sprite sprite_cabine;
    sf::Sprite sprite_scope;

public:
    Falcon_9();
    void draw_falcon(sf::RenderWindow &win) const;
    int get_speed();
};



#endif