#ifndef SPACETOUR__MENU_H
#define SPACETOUR__MENU_H

#include "Enemy.h"

enum GameState : int {RUNNING= 0, SETTINGS = 1, HOW_TO_PLAY = 2, START = 332, FINISHED = 333};

class Menu {

    float highlight_pos_y;

protected:
    sf::RectangleShape highlight;
    GameState current_state;
    GameMode game_mode;
    int state_int;
    bool start_screen;
    bool option_screen;

public:
    Menu();
    void set_state(int key);
    void batton_ctrl();
    std::string get_mode();
};



#endif
