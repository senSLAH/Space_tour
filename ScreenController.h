#ifndef SPACETOUR__SCREENCONTROLLER_H
#define SPACETOUR__SCREENCONTROLLER_H

#include "OpenSpace.h"
#include "Falcon_9.h"
#include "Enemies.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>


class ScreenController : public Menu{
    OpenSpace &space;
    Falcon_9 &falcon;
    Enemies &enemies;
    sf::RenderWindow &window;

    sf::Texture back_ground_txture;
    sf::Sprite back_ground;
    sf::Texture mode_txture;
    sf::Sprite mode;
    sf::Texture how_to_play_texure;
    sf::Sprite how_to_play_s;
    sf::Clock clock;


    int key;
    bool draw_stars_and_enemy;
    bool reset_check;
    bool restart_check_clock;
    std::string mode_string;

public:
    ScreenController(OpenSpace &s, Falcon_9 &f, Enemies &e, sf::RenderWindow &w);
    void handleEvent(sf::Event &e);

    void start_screen_func(sf::RenderWindow &win);

    //draw menu -> start, game play
    void game_play();

    //draw menu -> option
    void option_screem_func();

    //draw menu -> how to play
    void how_to_play_screen_func();

    //collition_laser() - return 100 if we didn't hit enemy, else it return
    //the index of enemy that we hit.
    int collition_laser();

    //str == "on" - means we see htem on the screen or not
    //str == "move" - we need to move enemies or not
    bool on_the_screen(int &x, int &y, std::string str = "on") const;

    void restart_clock();

    void reset();

    void draw();
};



#endif
