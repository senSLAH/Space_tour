#include <iostream>
#include "OpenSpace.h"

OpenSpace::OpenSpace()
{
    star_circle = sf::CircleShape(0.5);
    star_circle.setFillColor(sf::Color::White);
    space_clear = false;
}

void OpenSpace::set_main_star_position()
{
    Star s;
    for (int i = 0; i < 1000; ++i)
    {
        int x, y;
        x = rand() % 2560;
        y = rand() % 1440;
        //нрисовать схему
        if(rand()%2)
            x *= -1;
        if(rand()%2)
            y *= -1;
        s.star_position_x = x;
        s.star_position_y = y;
        stars.push_back(s);
    }
}
//center 640 360
void OpenSpace::set_star_position()
{
    for (int i = 0; i < stars.size(); ++i)
    {
        if (on_screen(stars[i].star_position_x, stars[i].star_position_y))
        {
            move_stars(stars[i].star_position_x, stars[i].star_position_y, i);
        }
    }
}

//
void OpenSpace::move_stars(float x, float y, int star_num)
{
    if (star_num == 5001)
    {
        x *=3;
        y *=3;
        for (int i = 0; i < stars.size(); ++i)
        {
            stars[i].star_position_x += x;
            stars[i].star_position_y += y;
        }
    }


    //x /= 1.7;
//    float max = (x > y)? x : y;
//    float min =
//    if (x > y)
//    {
//        float step = x/y;
//        x = step;
//        ++y;
//    }
//    if (x < y)
//    {
//        float step = y/x;
//        y = step;
//        ++x;
//    }
//    x -= 0.001;
//    y -= 0.001;
//    stars[star_num].star_position_x = x;
//    stars[star_num].star_position_y = y;
}

void OpenSpace::draw_star(sf::RenderWindow &win)
{
    for (int i = 0; i < stars.size(); ++i)
    {
        star_circle.setPosition(stars[i].star_position_x, stars[i].star_position_y);
        win.draw(star_circle);
    }
}

bool OpenSpace::on_screen(float &x, float &y)
{
    if (x < 0 || x > 1280)
        return false;
    if (y < 0 || y > 720)
        return false;
    return true;
}

void OpenSpace::move_all_stars(int movestars)
{
    std::cout << movestars;
    switch (movestars)
    {
        case 0:
            move_stars(1,0,5001);
            break;
        case 22:
            move_stars(0,1,5001);
            break;
        case 3:
            move_stars(-1,0,5001);
            break;
        case 18:
            move_stars(0,-1,5001);
            break;
    }
}




