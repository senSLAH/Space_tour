#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    last_state = current_state = START;
    last_state_int = state_int = 0;
    start_screen = true;

    highlight_pos_y = 179;

    highlight = sf::RectangleShape(sf::Vector2f(255, 40));
    highlight.setPosition(65, highlight_pos_y);
    highlight.setFillColor(sf::Color(132, 77, 248));

}

void Menu::set_state(int key)
{
    //36 - escape
    if (key == 36)
    {
        current_state = last_state;
        state_int = 0;
        start_screen = true;
    }
    else
    {
        last_state_int = state_int;
    }


    if (start_screen == true)
    {
        switch (key) {
            case 74:
                if (state_int >= 2)
                {
                    state_int = 0;
                    highlight_pos_y = 139;
                }
                else
                    ++state_int;
                highlight_pos_y += 40;
                break;
            case 73:
                if (state_int <= 0)
                {
                    state_int = 2;
                    highlight_pos_y = 299;
                }
                else
                    --state_int;
                highlight_pos_y -= 40;
                break;
            case 58:
                last_state = current_state;
                current_state = static_cast<GameState>(state_int);
                start_screen = false;
                break;
        }
    }

    highlight.setPosition(65, highlight_pos_y);


    //std::cout << "\nCurrent state: "<< static_cast<int>(current_state);

}

void Menu::draw_menu(sf::RenderWindow &win)
{

}


