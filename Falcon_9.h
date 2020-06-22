#ifndef SPACETOUR__FALCON_9_H
#define SPACETOUR__FALCON_9_H
#include <SFML/Graphics.hpp>


class Falcon_9 {

    sf::Font font;
    sf::Text score_txt;
    sf::Text score_num;
    sf::Text mode_txt;
    sf::Texture scope_texture;
    sf::Texture cabine_texture;
    sf::Sprite sprite_cabine;
    sf::Sprite sprite_scope;
    sf::RectangleShape healt_elem;

    bool left_laser;
    bool up_laser;
    bool right_laser;
    bool down_laser;
    bool laser_bool;
    bool right_or_left_laser;
    float scope_pos_x;
    float scope_pos_y;
    int health;
    float health_bar_position_x;
    int score;
    std::vector<sf::RectangleShape> health_bar;
    sf::Clock clock;
    sf::Time current_time;

public:
    Falcon_9();

    void lasers(sf::RenderWindow &win);
    void return_laser();
    bool hit(int damage);
    void increase_score(int s);
    std::string number_to_string(int num);
    void key_press(sf::Event &e, bool set);
    void set_health_bar();
    void set_laser_pos();
    float get_scope_pos_x() const;
    float get_scope_pos_y() const;
    bool get_laser_condition() const;
    void restart_clock();
    void reser_falcon();
    void draw_score(sf::RenderWindow &win, std::string str = "running");
    void draw_mode(sf::RenderWindow &win, std::string str_mode);
    void draw_falcon(sf::RenderWindow &win);
};



#endif