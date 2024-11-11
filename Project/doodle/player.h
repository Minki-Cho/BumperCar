// Filename : player.h
// Authors : Minjae Yu, Minki Cho, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include <cmath>

using namespace doodle;

struct vec2
{
    double x{ 0 };
    double y{ 0 };
};

struct Player_bool
{
    bool p1_front{ false };
    bool p1_back{ false };
    bool p1_left{ false };
    bool p1_right{ false };

    bool p2_front{ false };
    bool p2_back{ false };
    bool p2_left{ false };
    bool p2_right{ false };

    bool is_collide{ false };
    bool velocity_calculate{ false };

    bool p1_item{ false };
    bool p2_item{ false };
    bool p1_item2{ false };
    bool p2_item2{ false };

    bool p1_item_time{ false };
    bool p2_item_time{ false };

    bool p1_item2_time{ false };
    bool p2_item2_time{ false };

    bool is_p1_lose{ false };
    bool is_p2_lose{ false };
};

struct Player_img
{
    const Image car1{ "assets/red_bump.png" };
    const Image car2{ "assets/green_bump.png" };
    const Image big_car1{ "assets/red_bump2.png" };
    const Image big_car2{ "assets/green_bump2.png" };
    const Image small_car1{ "assets/red_bump_small.png" };
    const Image small_car2{ "assets/green_bump_small.png" };
    const Image car_light{ "assets/car_light.png" };
    vec2 img_pos{ 0,0 };
};

struct Acceleration
{ 
    vec2 p1{ 0,0 };
    vec2 p2{ 0,0 };
    const int zero{ 0 };
    const int increase_val{ 4 };
    const int decrease_val{ -4 };
};

struct Velocity
{
    vec2 p1{ 0,0 };
    vec2 p2{ 0,0 };
    vec2 p1_collision{ 0,0 };
    vec2 p2_collision{ 0,0 };
    const int zero{ 0 };
    const double value{ 3.5 };
    const double p_far{ 40 };
    const double close{ -20 };
    const double teleport_val{ 1000 };
};
struct Map_limit
{
    const int x1{ -400 };
    const int x2{ 400 };
    const int y1{ -400 };
    const int y2{ 400 };
};
struct Shaking
{
    const int value{ 0 };
    const double zero{ 0 };
    const double max{ 0.5 };
    const double min{ -0.5 };
    const double default_val{ 0.5 };
};

struct Light
{
    const double big_scale{ 1.5 };
    const double small_scale{ 0.7 };
    const int normal_scale{ 1 };
    const int tint_value{ 230 };
    const vec2 pos_light{ 50,0 };
};

using player_pos = double;
struct Player_pos
{
    player_pos player1_pos_x{ 200 };
    player_pos player1_pos_y{ 200 };
    player_pos player2_pos_x{ -200 };
    player_pos player2_pos_y{ -200 };
    vec2 player1{ 200,200 };
    vec2 player2{ -200,-200 };
};

class Player
{
public:
    Player_pos pos;
    Velocity velocity;
private:
    Player_img img;
    Acceleration acceleration;
    Map_limit map_limit;
    double player1_size{ 60 };
    double player2_size{ 60 };
    const double player_normal_size{ 60 };
    double player_transparent{ 100 };
    double player_tint{ 255 };
    //player angle
    double player1_angle{ atan2(pos.player1.y, pos.player1.x) };
    double player2_angle{ atan2(pos.player2.y, pos.player2.x) };
    double calculate_angle{ 0 };
    Light light;
    const int rotate_value{ 5 };
    //gameover
    const int gameover_count{ 50 };
public:
    void draw_player();
    void draw_light(double x, double y, double rotate, bool postive_item, bool negative_item);
    void keyboard_pressed(doodle::KeyboardButtons button);
    void keyboard_released(doodle::KeyboardButtons button);
    void player_movement();
    void player_collision();
    void map_player_collision();
    void screen_effect();
    vec2 get_player1_pos();
    vec2 get_player2_pos();
    Shaking shaking;
    double get_player1_size();
    double get_player2_size();
    void set_player1_size(double size);
    void set_player2_size(double size);
};
inline Player p;
inline Player state_p;
inline Player_bool pb;
inline double vibebration{ 0.5 };
constexpr double MaxOffset{ 100.0 };
constexpr double MaxAngle = doodle::QUARTER_PI / 2.0;