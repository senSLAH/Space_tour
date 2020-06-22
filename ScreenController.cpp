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
    if (!mode_txture.loadFromFile("../IMG/mode.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    back_ground.setTexture(back_ground_txture);
    mode.setTexture(mode_txture);
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
        game_play();
    }
    if (current_state == SETTINGS)
    {
        option_screem_func();
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

void ScreenController::game_play()
{
    sf::Time time = clock.getElapsedTime();

    //check laser colition,
    //get_laser_condition() -  return "true" if laser if laser shoots
    //collition_laser() - return 100 if we didn't hit enemy, else it return
    //the index of enemy that we hit.
    //remove_enemy() - will hit enemy, and if health of enemy equel "0" enemy will
    //be removed and than this function execute func add_anamy()
    if (falcon.get_laser_condition())
    {
        int enemy_n = collition_laser();
        if (enemy_n != 100)
        {
            enemies.remove_enemy(enemy_n);
        }
    }

    //Move enemy back to the screen
    for (int i = 0; i < enemies.get_enemies_count(); ++i)
    {
        int pos_x = enemies.get_enemy(i).get_position().position_x;
        int pos_y = enemies.get_enemy(i).get_position().position_y;

        if (on_the_screen(pos_x, pos_y,"move"))
        {
            enemies.move_back_to_screen(i);
        }
        if (on_the_screen(pos_x, pos_y))
        {
            int damage = enemies.attack(window);
            if (!falcon.hit(damage))
            {
                std::cout << "dead!\n";
                set_state(0,FINISHED);
            }

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

void ScreenController::option_screem_func()
{
    window.draw(mode);
}

bool ScreenController::on_the_screen(int &x, int &y, std::string str) const
{
    if ((x >= 1020 || x <= 100 || y <= 100 || y > 440) && (str == "move"))
    {
        return true;
    }
    if(x <= 1120 && x >= 0 && y >= 0 && y < 540 && str == "on")
    {
        return true;
    }
    return false;
}



