// Filename : item.cpp
// Authors : Minki Cho, Minjae Yu, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include "item.h"
#include "player.h"
#include "sfml-sound.h"

using namespace doodle;

void Item::item_draw()
{
    push_settings();
    set_image_mode(RectMode::Center);
    draw_image(apple, x, y);
    pop_settings();

    if (pb.p1_item == true || pb.p2_item == true)
    {
        x = random(random_min_pos, random_max_pos);
        y = random(random_min_pos, random_max_pos);
    }
}
void Item::item_collision()
{
    vec2 player1_vector{ zero_vector,zero_vector };
    vec2 player2_vector{ zero_vector,zero_vector };
    player1_vector = p.get_player1_pos();
    player2_vector = p.get_player2_pos();

    double p1_dis_x{ player1_vector.x - x };
    double p1_dis_y{ player1_vector.y - y };
    double p2_dis_x{ player2_vector.x - x };
    double p2_dis_y{ player2_vector.y - y };

    //player 1 item distance
    if (sqrt(p1_dis_x * p1_dis_x + p1_dis_y * p1_dis_y) < (item_size + p.get_player1_size()) / 2)
    {
        game_sound.Playsound(static_cast<int>(Sounds::eat_apple));
        pb.p1_item = true;
        pb.p1_item_time = true;
    }
    else
    {
        pb.p1_item = false;
    }
    //player 1 item in function
    if (pb.p1_item_time == true)
    {
        p.set_player1_size(player_size_big);
        p1_time--;
    }
    if (p1_time < zero_time)
    {
        pb.p1_item_time = false;
        p.set_player1_size(player_size_normal);
        p1_time = time_limit;
    }
    //player 2 item distance
    if (sqrt(p2_dis_x * p2_dis_x + p2_dis_y * p2_dis_y) < (item_size + p.get_player2_size()) / 2)
    {
        game_sound.Playsound(static_cast<int>(Sounds::eat_apple));
        pb.p2_item = true;
        pb.p2_item_time = true;
    }
    else
    {
        pb.p2_item = false;
    }
    //player 2 item in function
    if (pb.p2_item_time == true)
    {
        p.set_player2_size(player_size_big);
        p2_time--;
    }
    if (p2_time < zero_time)
    {
        pb.p2_item_time = false;
        p.set_player2_size(player_size_normal);
        p2_time = time_limit;
    }
}

void Item2::item_draw()
{
    push_settings();
    set_image_mode(RectMode::Center);
    draw_image(apple_bad, x, y);
    pop_settings();

    if (pb.p1_item2 == true || pb.p2_item2 == true)
    {
        x = random(random_min_pos, random_max_pos);
        y = random(random_min_pos, random_max_pos);
    }
}
void Item2::item_collision()
{
    vec2 player1_vector{ zero_vector,zero_vector };
    vec2 player2_vector{ zero_vector,zero_vector };
    player1_vector = p.get_player1_pos();
    player2_vector = p.get_player2_pos();

    double p1_dis_x{ player1_vector.x - x };
    double p1_dis_y{ player1_vector.y - y };
    double p2_dis_x{ player2_vector.x - x };
    double p2_dis_y{ player2_vector.y - y };

    //player 1 item distance
    if (sqrt(p1_dis_x * p1_dis_x + p1_dis_y * p1_dis_y) < (item_size + p.get_player1_size()) / 2)
    {
        game_sound.Playsound(static_cast<int>(Sounds::eat_apple));
        pb.p1_item2 = true;
        pb.p1_item2_time = true;
    }
    else
    {
        pb.p1_item2 = false;
    }
    //player 1 item in function
    if (pb.p1_item2_time == true)
    {
        p.set_player1_size(player_size_small);
        p1_time--;
    }
    if (p1_time < zero_time)
    {
        pb.p1_item2_time = false;
        p.set_player1_size(player_size_normal);
        p1_time = time_limit;
    }
    //player 2 item distance
    if (sqrt(p2_dis_x * p2_dis_x + p2_dis_y * p2_dis_y) < (item_size + p.get_player2_size()) / 2)
    {
        game_sound.Playsound(static_cast<int>(Sounds::eat_apple));
        pb.p2_item2 = true;
        pb.p2_item2_time = true;
    }
    else
    {
        pb.p2_item2 = false;
    }
    //player 2 item in function
    if (pb.p2_item2_time == true)
    {
        p.set_player2_size(player_size_small);
        p2_time--;
    }
    if (p2_time < zero_time)
    {
        pb.p2_item2_time = false;
        p.set_player2_size(player_size_normal);
        p2_time = time_limit;
    }
}