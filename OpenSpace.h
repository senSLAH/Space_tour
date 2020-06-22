#ifndef SPACETOUR__OPENSPACE_H
#define SPACETOUR__OPENSPACE_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemies.h"

enum MOVESTARS {UP = 22, DOWN = 18, LEFT = 0, RIGHT = 3};

struct Star
{
    float star_position_x;
    float star_position_y;
};

class OpenSpace {
    std::vector<Star> stars;
    sf::CircleShape star_circle;
    bool up;
    bool down;
    bool left;
    bool right;

    sf::Texture moon_texture;
    sf::Sprite moon;
    Enemies &enemies;
    sf::Clock clock;
    sf::Time current_time;

public:
    OpenSpace(Enemies &e);
    void add_star();
    void remove_star();
    bool on_screen(float &x, float &y);
    void set_main_star_position();
    void move_stars(float x, float y, int star_num = 0);
    void move_falcon(int &i);
    int screen_part(float x, float y);
    void check_edges();
    void set_star_position();
    int get_star_count() const;
    void key_press(sf::Event &e, bool set);
    void draw_star(sf::RenderWindow &win);
    void restart_clock();
    void reset_space();
};




#endif