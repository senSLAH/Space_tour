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
    for (int i = 0; i < 5000; ++i)
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

void OpenSpace::set_star_position()
{
    for (int i = 0; i < stars.size(); ++i)
    {
        if (on_screen(stars[i].star_position_x, stars[i].star_position_y))
        {

        }
    }
}

void OpenSpace::draw_star(sf::RenderWindow &win)
{
    for (int i = 0; i < stars.size(); ++i)
    {
        star_circle.setPosition(stars[i].star_position_x, stars[i].star_position_y);
        win.draw(star_circle);
    }
}

bool OpenSpace::on_screen(int x, int y)
{
    if (x < 0 || x > 1280)
        return false;
    if (y < 0 || y > 720)
        return false;
    return true;
}


