#ifndef SPACETOUR__OPENSPACE_H
#define SPACETOUR__OPENSPACE_H


#include <vector>
#include <SFML/Graphics.hpp>

enum MOVESTARS {UP = 22, DOWN = 18, LEFT = 0, RIGHT = 3};

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
    void remove_star(float &x, float &y, int &n);
    bool on_screen(float &x, float &y);
    void set_main_star_position();
    void move_stars(float x, float y, int star_num = 0);
    void move_all_stars(int movestars);
    void check_edges();
    void set_star_position();
    void set_speed();
    int get_star_count();
    int get_star_position_x();
    int get_star_position_y();
    void draw_star(sf::RenderWindow &win);
};




#endif