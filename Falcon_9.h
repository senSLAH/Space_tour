#ifndef SPACETOUR__FALCON_9_H
#define SPACETOUR__FALCON_9_H
#include <SFML/Graphics.hpp>


class Falcon_9 {
    int speed;
    sf::RectangleShape scope;
    sf::Texture cabine_texture;
    sf::Sprite cabine;

public:
    Falcon_9();
    void draw_falcon(sf::RenderWindow &win);
    int get_speed();
};



#endif