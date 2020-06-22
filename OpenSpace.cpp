#include <iostream>
#include "OpenSpace.h"

OpenSpace::OpenSpace(Enemies &e): enemies(e)
{
    star_circle = sf::CircleShape(0.7);
    star_circle.setFillColor(sf::Color::White);
    space_clear = false;
    proverka = true;
    left = false;
    up = false;
    right = false;
    down = false;
}

void OpenSpace::set_main_star_position()
{
    Star s;
    for (int i = 0; i < 100; ++i)
    {
        int x, y;
        //нрисовать схему

        if(rand()%2)
        {
            x = rand() % 1600;
        } else{
            x = rand() % 300;
            x *= -1;
        }
        if (rand()%2)
        {
            y = rand() % 900;
        } else{
            y = rand() % 180;
            y *= -1;
        }

        s.star_position_x = x;
        s.star_position_y = y;
        stars.push_back(s);
    }
}
//center 640 360
void OpenSpace::set_star_position()
{
    if (current_time.asMicroseconds() > 1)
    {
        for (int i = 0; i < stars.size(); ++i)
        {
            move_stars(stars[i].star_position_x, stars[i].star_position_y, i);
        }
        clock.restart();
    }

    for (int i = 0; i < stars.size(); ++i)
    {
        move_falcon(i);
    }

    remove_star();
}

//
void OpenSpace::move_stars(float x, float y, int star_num)
{
    int screen_p = screen_part(x,y);

    switch (screen_p)
    {
        case 1:
            x -= 0.1 * 1.8;
            y -= 0.1;
            break;

        case 2:
            x += 0.1 * 1.8;
            y -= 0.1;
            break;

        case 3:
            x += 0.1 * 1.8;
            y += 0.1;
            break;

        case 4:
            x -= 0.1 * 1.8;
            y += 0.1;
            break;
    }

    stars[star_num].star_position_x = x;
    stars[star_num].star_position_y = y;
    remove_star();
}

void OpenSpace::draw_star(sf::RenderWindow &win)
{
    sf::Time time = clock.getElapsedTime();
    current_time = time;
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

void OpenSpace::move_falcon(int &i)
{
    int check = enemies.get_enemies_count();

    if (left)
    {
        stars[i].star_position_x += 2;
        if (i < check)
            enemies.set_position(i,6,0);
    }
    if (up)
    {
        stars[i].star_position_y += 2;
        if (i < check)
            enemies.set_position(i,0,6);
    }
    if (right)
    {
        stars[i].star_position_x -= 2;
        if (i < check)
            enemies.set_position(i,-6,0);
    }
    if (down)
    {
        stars[i].star_position_y -= 2;
        if (i < check)
            enemies.set_position(i,0,-6);
    }
}

void OpenSpace::key_press(sf::Event &e, bool set)
{
    int key = e.key.code;
    //std::cout << key;
    switch (key)
    {
        case 0:
            left = set;
            break;
        case 22:
            up = set;
            break;
        case 3:
            right = set;
            break;
        case 18:
            down = set;
            break;
    }
}

void OpenSpace::remove_star()
{
    for (int i = 0; i < stars.size(); ++i)
    {
        if(stars[i].star_position_x > 1600 || stars[i].star_position_x < -300 ||
                stars[i].star_position_y > 900 || stars[i].star_position_y < -180)
        {
            stars.erase(stars.begin() + i);
            add_star();
        }
    }
}

void OpenSpace::add_star()
{
    int x, y;

    x = rand() % 423 + 423;
    y = rand() % 240 + 240;

    Star s;
    s.star_position_x = x;
    s.star_position_y = y;
    stars.push_back(s);
}

int OpenSpace::get_star_count() const
{
    return stars.size();
}

int OpenSpace::screen_part(float x, float y)
{
    if (x < 640)
    {
        if (y <= 360) ////////first
        {
            return 1;
        }
        if(y > 360) ////////four
        {
            return 4;
        }
    }
    if (x > 640)
    {
        if (y <= 360) //////////two
        {
            return 2;
        }
        if (y > 360)/////////three
        {
            return 3;
        }
    }
    return 0;
}






