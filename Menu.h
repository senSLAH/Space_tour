#ifndef SPACETOUR__MENU_H
#define SPACETOUR__MENU_H


enum GameState : int {START= 0, SETTINGS = 1, HOW_TO_PLAY = 2, RUNNING = 332, FINISHED = 333};

class Menu {

    int highlight_pos_y;

protected:
    sf::RectangleShape highlight;
    GameState current_state;
    GameState last_state;
    int state_int;
    int last_state_int;
    bool start_screen;


public:
    Menu();
    void set_state(int key);
    void draw_menu(sf::RenderWindow &win);

    //GameState get_state();
};



#endif
