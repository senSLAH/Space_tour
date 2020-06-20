#include <iostream>
#include "OpenSpace.h"

OpenSpace::OpenSpace()
{
    star_circle = sf::CircleShape(0.7);
    star_circle.setFillColor(sf::Color::White);
    space_clear = false;
    time = ((float)clock()) / CLOCKS_PER_SEC;
    proverka = true;
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
     //for (int i = 0; i < stars.size(); ++i)
//         if ((float) clock() / CLOCKS_PER_SEC - time >= 0.00001 || proverka)
//         {
             for (int i = 0; i < stars.size(); ++i)
             {
                 //if (on_screen(stars[i].star_position_x, stars[i].star_position_y))
                 //{
                 move_stars(stars[i].star_position_x, stars[i].star_position_y, i);
                // proverka = false;
                 //time = (float) clock() / CLOCKS_PER_SEC;
                 //}
             }
         //}
    remove_star();

}

//
void OpenSpace::move_stars(float x, float y, int star_num)
{
    int screen_p = screen_part(x,y),
        m_x = 1, m_y = 1;
    if (star_num == 5001)
    {
        x *=1;
        y *=1;
        for (int i = 0; i < stars.size(); ++i)
        {
            stars[i].star_position_x += x;
            stars[i].star_position_x += x;
            stars[i].star_position_y += y;
            stars[i].star_position_y += y;
        }
    }

////////1:1
     //m_y = x /1.8;

//    float max = (x > y)? x : y;
//    float min = (y > x)? y : x;


    switch (screen_p)
    {
        case 1:
            x -= 1 * m_x * 1.8;
            y -= 1 * m_y;
            break;

        case 2:
            x += 1 * m_x * 1.8;
            y -= 1 * m_y;
            break;

        case 3:
            x += 1 * m_x * 1.8;
            y += 1 * m_y;
            break;

        case 4:
            x -= 1 * m_x * 1.8;
            y += 1 * m_y;
            break;
    }

    stars[star_num].star_position_x = x;
    stars[star_num].star_position_y = y;
    remove_star();
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
    //std::cout << movestars;
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

void OpenSpace::check_edges()
{

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

