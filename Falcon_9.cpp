#include <iostream>
#include "Falcon_9.h"
#include "sstream"
#include <cstring>


Falcon_9::Falcon_9()
{
    if (!font.loadFromFile("../Fonts/Arial.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!cabine_texture.loadFromFile("../IMG/cabine1.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!scope_texture.loadFromFile("../IMG/scope.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    left_laser = false;
    up_laser = false;
    right_laser = false;
    down_laser = false;
    laser_bool = false;
    right_or_left_laser = true;

    score = 0;
    health = 50;

    healt_elem = sf::RectangleShape(sf::Vector2f(5, 20));
    healt_elem.setFillColor(sf::Color::Red);
    health_bar_position_x = 5;

    sprite_cabine.setPosition(0, 0);
    sprite_cabine.setTexture(cabine_texture);
    sprite_cabine.setRotation(2);
    sprite_cabine.setScale(1, 1.05);
    sprite_cabine.setPosition(0, -40);


    scope_pos_x = 640;
    scope_pos_y = 360;

    sprite_scope.setTexture(scope_texture);
    sprite_scope.setPosition(scope_pos_x, scope_pos_y);

    score_txt.setFont(font);
    score_txt.setString("Score: ");
    score_txt.setFillColor(sf::Color(132, 77, 248));
    score_txt.setPosition(1110,5);

    score_num.setFont(font);
    score_num.setFillColor(sf::Color(132, 77, 248));
    score_num.setPosition(1215,5);

    mode_txt.setFont(font);
    mode_txt.setPosition(1040,670);
    mode_txt.setFillColor(sf::Color(132, 77, 248));
}

void Falcon_9::lasers(sf::RenderWindow &win)
{
    sf::VertexArray laser1(sf::Quads,4);
    sf::VertexArray laser2(sf::Triangles,3);

    laser1[0].position = sf::Vector2f (339,541);
    laser1[1].position = sf::Vector2f (433,541);
    laser1[2].position = sf::Vector2f (444,575);
    laser1[3].position = sf::Vector2f (scope_pos_x+40,scope_pos_y+40);
    laser1[0].color = sf::Color::Green;
    laser1[1].color = sf::Color::Green;
    laser1[2].color = sf::Color::Green;
    laser1[3].color = sf::Color::Red;

    laser2[0].position = sf::Vector2f (945,515);
    laser2[1].position = sf::Vector2f (950,510);
    laser2[2].position = sf::Vector2f (scope_pos_x + 40,scope_pos_y + 40);
    laser2[0].color = sf::Color::Red;
    laser2[1].color = sf::Color::Red;
    laser2[2].color = sf::Color(137, 19, 145);

    if (laser_bool)
    {
        if (right_or_left_laser)
        {
            win.draw(laser1);
        }
        else
        {
            win.draw(laser2);
        }
        if(current_time.asMilliseconds() > 70)
        {
            (right_or_left_laser)? right_or_left_laser = false : right_or_left_laser = true;
            clock.restart();
        }
    }
}

void Falcon_9::set_laser_pos()
{
    if (left_laser)
        scope_pos_x -= 5;
    if (up_laser)
        scope_pos_y -= 5;
    if (right_laser)
        scope_pos_x += 5;
    if (down_laser)
        scope_pos_y += 5;

    return_laser();
    sprite_scope.setPosition(scope_pos_x, scope_pos_y);
}

void Falcon_9::key_press(sf::Event &e, bool set)
{
    int key = e.key.code;

    switch (key)
    {
        case 71:
            left_laser = set;
            break;
        case 73:
            up_laser = set;
            break;
        case 72:
            right_laser = set;
            break;
        case 74:
            down_laser = set;
            break;
        case 57:
            laser_bool = set;
    }
}

void Falcon_9::return_laser()
{
    if (!(left_laser || up_laser || right_laser || down_laser))
    {
        if (scope_pos_x > 640)
            scope_pos_x -= 3;
        if (scope_pos_x < 640)
            scope_pos_x += 3;
        if (scope_pos_y > 360)
            scope_pos_y -= 3;
        if (scope_pos_y < 360)
            scope_pos_y += 3;
    }
}

float Falcon_9::get_scope_pos_x() const
{
    return scope_pos_x;
}

float Falcon_9::get_scope_pos_y() const
{
    return scope_pos_y;
}

bool Falcon_9::get_laser_condition() const
{
    return laser_bool;
}

void Falcon_9::set_health_bar()
{
    for (int i = 0; i < health; ++i)
    {
        health_bar_position_x += 7;
        healt_elem.setPosition(health_bar_position_x,5);
        health_bar.push_back(healt_elem);
    }
}

bool Falcon_9::hit(int damage)
{
    if (health >= damage)
    {
        health -= damage;
        return true;
    }
    return false;
}

void Falcon_9::draw_falcon(sf::RenderWindow &win)
{
    sf::Time time = clock.getElapsedTime();
    current_time = time;
    set_health_bar();
    win.draw(sprite_scope);
    win.draw(sprite_cabine);
    draw_score(win);
    for (int i = 0; i < health; ++i)
    {
        win.draw(health_bar[i]);
    }
}

void Falcon_9::draw_score(sf::RenderWindow &win, std::string str)
{
    if(str == "finish")
    {
        score_txt.setPosition(560,350);
        score_num.setPosition(675,350);
    }
    win.draw(score_txt);
    score_num.setString(number_to_string(score));
    win.draw(score_num);
}

void Falcon_9::draw_mode(sf::RenderWindow &win, std::string str_mode)
{
    mode_txt.setString(str_mode);
    win.draw(mode_txt);
}

void Falcon_9::increase_score(int s)
{
    score += s;
}

void Falcon_9::restart_clock()
{
    clock.restart();
}

void Falcon_9::reser_falcon()
{
    scope_pos_x = 640;
    scope_pos_y = 360;
    sprite_scope.setPosition(scope_pos_x, scope_pos_y);
    health = 50;
    score = 0;
    score_txt.setPosition(1110,5);
    score_num.setPosition(1215,5);
    left_laser = false;
    up_laser = false;
    right_laser = false;
    down_laser = false;
    laser_bool = false;
    right_or_left_laser = true;
}

std::string Falcon_9::number_to_string(int num)
{
    std::stringstream score;
    score << num << std::endl;
    return score.str();
}






