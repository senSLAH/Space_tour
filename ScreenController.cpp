#include <iostream>
#include "ScreenController.h"
#include <cstring>


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
    if (!how_to_play_texure.loadFromFile("../IMG/how_to_play.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    key = 0;
    draw_stars_and_enemy = true;
    reset_check = false;
    restart_check_clock = true;
    back_ground.setTexture(back_ground_txture);
    mode.setTexture(mode_txture);
    how_to_play_s.setTexture(how_to_play_texure);
    mode_string = "Mode: HERO";
}

void ScreenController::handleEvent(sf::Event &event)
{
    key = event.key.code;
    set_state(key);
    space.move_falcon(key);
}

void ScreenController::draw()
{
    mode_string = get_mode();
    if (current_state == START && start_screen)
    {
        if (reset_check)
            reset();
        window.draw(highlight);
        start_screen_func(window);
        restart_check_clock = true;
    }
    if (current_state == RUNNING)
    {
        reset_check = true;
        game_play();
    }
    if (current_state == FINISHED)
    {
        falcon.draw_score(window, "finish");
    }
    if (current_state == SETTINGS)
    {
        window.draw(highlight);
        option_screem_func();
    }
    if (current_state == HOW_TO_PLAY)
    {
        window.draw(how_to_play_s);
    }
}

void ScreenController::start_screen_func(sf::RenderWindow &win)
{
    win.draw(back_ground);
    falcon.draw_mode(win,mode_string);
}

void ScreenController::game_play()
{
    if (restart_check_clock)
        restart_clock();

    if (draw_stars_and_enemy)
    {
        for (int i = 0; i < game_mode + 1; ++i)
        {
            enemies.add_enemy(game_mode);
        }
        draw_stars_and_enemy = false;
        space.set_main_star_position();
    }
    sf::Time time = clock.getElapsedTime();

    //check laser colition,
    //get_laser_condition() -  return "true" if laser if laser shoots
    //collition_laser() - return 100 if we didn't hit enemy, else it return
    //the index of enemy that we hit.
    //remove_enemy() - will hit enemy, and if health of enemy equel "0" enemy will
    //be removed and than this function execute func add_enamy()
    if (falcon.get_laser_condition())
    {
        int enemy_n = collition_laser();
        if (enemy_n != 100)
        {
            falcon.increase_score(enemies.remove_enemy(enemy_n, game_mode));
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
                set_state(99);
            }
        }
    }
    space.set_star_position();
    space.draw_star(window);
    enemies.draw_enemys(window);
    falcon.set_laser_pos();
    falcon.lasers(window);
    falcon.draw_falcon(window);
    falcon.draw_mode(window,mode_string);
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
    option_screen = true;
    window.draw(mode);
    falcon.draw_mode(window,mode_string);
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

void ScreenController::restart_clock()
{
    restart_check_clock = false;
    enemies.restart_clock();
    falcon.restart_clock();
    space.restart_clock();
    clock.restart();
}

void ScreenController::reset()
{
    std::cout << "reset! \n";
    draw_stars_and_enemy = true;
    reset_check = false;
    space.reset_space();
    falcon.reser_falcon();
    enemies.reset_enemies();
}





