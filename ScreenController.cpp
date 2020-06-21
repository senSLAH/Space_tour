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
    enemies.add_enemy();
    enemies.add_enemy();
}

void ScreenController::handleEvent(sf::Event &event)
{
    key = event.key.code;
    //std::cout << key;

    if (current_state != FINISHED)
    {
        set_state(key);
    }

    space.move_falcon(key);
}

void ScreenController::draw()
{
    if (current_state == START && start_screen)
    {
        window.draw(highlight);
        start_screen_func(window);

    }
    if (current_state == RUNNING)
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
    if (falcon.get_laser_condition())
    {
        int enemy_n = collition_laser();
        if (enemy_n != 100)
        {
            enemies.remove_enemy(enemy_n);
        }
    }

    space.set_star_position();
    space.draw_star(window);
    enemies.draw_enemys(window);
    falcon.set_laser_pos();
    falcon.lasers(window);
    falcon.draw_falcon(window);
}

int ScreenController::collition_laser()
{
    int scope_x = falcon.get_scope_pos_x() + 40;
    int scope_y = falcon.get_scope_pos_y() + 40;

    for (int i = 0; i < enemies.get_enemies_count(); ++i)
    {
        int enemy_pos_x = enemies.get_enemy(i).get_position().position_x + 21;
        int enemy_pos_y = enemies.get_enemy(i).get_position().position_y + 10;
        if (scope_x >= enemy_pos_x && scope_x <= enemy_pos_x + 125
        && scope_y >= enemy_pos_y && scope_y <= enemy_pos_y + 58)
        {
            return i;
        }
    }
    return 100;
}



