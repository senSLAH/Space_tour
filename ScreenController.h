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


public:
    ScreenController(OpenSpace &s, Falcon_9 &f, Enemies &e, sf::RenderWindow &w);
    void handleEvent(sf::Event &e);
    void draw_gameplay(sf::RenderWindow &win) const;
    void start_screen_func(sf::RenderWindow &win);
    void option_screem_func();
    void how_to_play_screen_func();
    void running();
    void draw();

};



#endif
