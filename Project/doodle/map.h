// Filename : map.h
// Authors : Minki Cho, Minjae Yu, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>

inline bool is_player1_lose{ false };
inline bool is_player2_lose{ false };

struct Doughnut
{
    int x{ 0 };
    int y{ 0 };
};
class Map
{
    const doodle::Image shadow{ "assets/shadow.png" };
    const doodle::Image doughnut_img{ "assets/Doughnut_Map.png"};
    const doodle::Image black_hole{ "assets/blackhole.png" };
    doodle::Color inside{255, 255, 182 };
    int inside_x{ 0 };
    int inside_y{ 0 };
    int collision_dis1{ 400 };
    int collision_dis2{ 150 };
    int inside_size{ 300 };
    int map_x{ 0 };
    int map_y{ 0 };
    int map_width{ 800 };
    int map_height{ 800 };
    double pos_x = (doodle::random(-350.0, 350.0));
    double pos_y = (doodle::random(-350.0, 350.0));
    double color_val{ 255 };
    int sink_hole_size{ 200 };
    int time_limit{ 2000 };
    int zero_time{ 0 };
    double random_min{ -330.0 };
    double random_max{ 330.0 };
    double color_white{ 255 };
    double color_decrease{ 0.5 };
    int color_black{ 0 };
    int outline_width{ 10 };
    int collision_val{ 100 };
    double zero_vector{ 0 };
    int add_color_val{ 50 };
    int set_frame60{ 60 };
    int set_frame50{ 50 };

    Doughnut doughnut;

public:
    void rectangleMap_draw(int x = 25, int y = -25);
    void random_sink_hole();
    void sink_hole_collision();
    void set_color_val(int val);
    void make_defalt();
    void doughnutMap_draw();
    void doughnutMap_collision();
};
inline Map map;