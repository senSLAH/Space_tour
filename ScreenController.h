#ifndef SPACETOUR__SCREENCONTROLLER_H
#define SPACETOUR__SCREENCONTROLLER_H

#include "OpenSpace.h"
#include "OpenSpace.h"
#include <SFML/Graphics.hpp>


class ScreenController {
    OpenSpace &space;
public:
    ScreenController(OpenSpace &space);
    void handleEvent(sf::Event &e);
    void draw_gameplay(sf::RenderWindow &win);

};



#endif
