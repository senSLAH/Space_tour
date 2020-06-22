#include <SFML/Graphics.hpp>
#include "Menu.h"

Menu::Menu()
{
    current_state = START;
    state_int = 0;
    start_screen = true;
    option_screen = false;
    game_mode = HERO;

    highlight_pos_y = 179;
    highlight = sf::RectangleShape(sf::Vector2f(255, 40));
    highlight.setPosition(65, highlight_pos_y);
    highlight.setFillColor(sf::Color(132, 77, 248));
}

void Menu::set_state(int key)
{
    //36 - escape
    if (key == 36 && !start_screen)
    {
        current_state = START;
        state_int = 0;
        highlight_pos_y = 179;
        start_screen = true;
        option_screen = false;
    }

    if (key == 99)
    {
        current_state = FINISHED;
        return;
    }

    if (start_screen || option_screen)
    {
        switch (key) {
            case 74:
                if (state_int >= 2)
                {
                    state_int = 0;
                    highlight_pos_y = 139;
                }
                else
                {
                    ++state_int;
                }
                highlight_pos_y += 40;
                break;
            case 73:
                if (state_int <= 0)
                {
                    state_int = 2;
                    highlight_pos_y = 299;
                }
                else
                {
                    --state_int;
                }
                highlight_pos_y -= 40;
                break;
            case 58:
                batton_ctrl();
                state_int = 0;
                highlight_pos_y = 179;
                break;
        }
    }
    highlight.setPosition(65, highlight_pos_y);
}

void Menu::batton_ctrl()
{
    if(current_state == START)
    {
        current_state = static_cast<GameState>(state_int);
        start_screen = false;
    }
    else if (current_state == SETTINGS)
    {

        game_mode = static_cast<GameMode>(state_int);
        start_screen = true;
        option_screen = false;
        current_state = START;
    }
}

std::string Menu::get_mode()
{
    if (game_mode == 0)
    {
        return "Mode: NORMAL";
    }
    if (game_mode == 1)
    {
        return "Mode: HERO";
    }
    if (game_mode == 2)
    {
        return "Mode: GOD";
    }
    return "";
}






