#include <iostream>
#include "ScreenController.h"


ScreenController::ScreenController(OpenSpace &s, Falcon_9 &f, Enemies &e, sf::RenderWindow &w)
:space(s), falcon(f), enemies(e), window(w)
{
    if (!back_ground_txture.loadFromFile("../IMG/main_manu.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    back_ground.setTexture(back_ground_txture);

    space.set_main_star_position();
}

void ScreenController::handleEvent(sf::Event &event)
{
    int key = event.key.code;
    //std::cout << key;
    if (current_state != FINISHED)
    {
        set_state(key);
    }

    space.move_all_stars(key);
}

void ScreenController::draw()
{
    if (current_state == START && start_screen)
    {
        window.draw(highlight);
        start_screen_func(window);

    }
    if (current_state == START && start_screen == false)
    {
        running();
    }
    if (current_state == SETTINGS)
    {
        std::cout << "SETTINGS\n";
    }
    if (current_state == HOW_TO_PLAY)
    {
        std::cout << "HOW_TO\n";
    }
}

void ScreenController::start_screen_func(sf::RenderWindow &win)
{
    win.draw(back_ground);
}

void ScreenController::running()
{
    space.set_star_position();
    space.draw_star(window);
    falcon.draw_falcon(window);
}
