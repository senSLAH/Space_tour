#ifndef SPACETOUR__OPENSPACE_H
#define SPACETOUR__OPENSPACE_H


#include <vector>
#include <SFML/Graphics.hpp>


struct Star
{
    float star_position_x;
    float star_position_y;
};

class OpenSpace {
    int star_counter;
    bool space_clear;
    std::vector<Star> stars;
    sf::CircleShape star_circle;
public:
    OpenSpace();
    void add_star();
    void remove_star();
    bool on_screen(int x, int y);
    void set_main_star_position();
    void set_star_position();
    void set_speed();
    int get_star_count();
    int get_star_position_x();
    int get_star_position_y();
    void draw_star(sf::RenderWindow &win);
};




#endif