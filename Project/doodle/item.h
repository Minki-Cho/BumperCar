// Filename : item.h
// Authors : Minki Cho, Minjae Yu, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>

using namespace doodle;

class Item
{
    const Image apple{ "assets/apple2.png" };
    const double random_min_pos{ -300 };
    const double random_max_pos{ 300 };
    double x{ doodle::random(random_min_pos,random_max_pos) };
    double y{ doodle::random(random_min_pos,random_max_pos) };
    const int item_size{ 10 };

    const double time_limit{ 300 };
    double p1_time{ time_limit };
    double p2_time{ time_limit };

    double player_size_normal{ 60 };
    double player_size_big{ 90 };
    double zero_time{ 0 };
    double zero_vector{ 0 };
public:
    void item_draw();
    void item_collision();
};
inline Item item;

class Item2
{
    const Image apple_bad{ "assets/apple1.png" };
    const double random_min_pos{ -300 };
    const double random_max_pos{ 300 };
    double x{ doodle::random(random_min_pos,random_max_pos) };
    double y{ doodle::random(random_min_pos,random_max_pos) };
    const int item_size{ 25 };

    const double time_limit{ 300 };
    double p1_time{ 200 };
    double p2_time{ 200 };

    double player_size_small{ 40 };
    double player_size_normal{ 60 };
    double zero_time{ 0 };
    double zero_vector{ 0 };
public:
    void item_draw();
    void item_collision();
};
inline Item2 item2;