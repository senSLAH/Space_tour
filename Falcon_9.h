#ifndef SPACETOUR__FALCON_9_H
#define SPACETOUR__FALCON_9_H
#include <SFML/Graphics.hpp>


class Falcon_9 {
    int speed;
    sf::Texture scope_texture;
    sf::Texture cabine_texture;
    sf::Sprite sprite_cabine;
    sf::Sprite sprite_scope;
    sf::VertexArray laser;

    bool left_laser;
    bool up_laser;
    bool right_laser;
    bool down_laser;
    bool laser_bool;
    bool right_or_left_laser;
    int scope_pos_x;
    int scope_pos_y;

public:
    Falcon_9();
    void draw_falcon(sf::RenderWindow &win) const;
    void lasers(sf::RenderWindow &win);
    void key_press(sf::Event &e, bool set);
    void set_laser_pos();
    int get_scope_pos_x() const;
    int get_scope_pos_y() const;
    bool get_laser_condition() const;
    void return_laser();
    int get_speed();
};



#endif