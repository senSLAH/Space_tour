#include "ScreenController.h"
#include <iostream>

ScreenController::ScreenController(OpenSpace &s):space(s)
{
    space.set_main_star_position();
}

void ScreenController::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        int key = event.key.code;
        //std::cout << key;
        space.move_all_stars(key);
    }
}
