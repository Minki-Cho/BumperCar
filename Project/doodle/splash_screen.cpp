// Filename : splash_screen.cpp
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include <math.h>
#include "splash_screen.h"
#include "state.h"
#include "sfml-sound.h"

using namespace doodle;

void splash_screen()
{
    using namespace logo;
    
    if (ElapsedTime <= one_second)
    {
        push_settings();
        apply_scale(scale_value);
        draw_image(black_logo, black_logo_x, black_logo_y);
        pop_settings();
    }
    else
    {
        push_settings();
        set_tint_color(tint_value, tint_value);
        apply_rotate(sin(to_degrees(rotate_value)));
        apply_scale(scale_value);
        draw_image(red_logo, red_logo_x, red_logo_y);

        rotate_value += rotation_increase_value;
        scale_value += scale_increase_value;
        tint_value--;
        pop_settings();

    }
    if (ElapsedTime >= one_second)
        draw_image(hash_h, hash_h_x, hash_h_y);
    if (ElapsedTime >= two_second)
        draw_image(hash_a, hash_a_x, hash_a_y);
    if (ElapsedTime >= three_second)
        draw_image(hash_s, hash_s_x, hash_s_y);
    if (ElapsedTime >= four_second)
        draw_image(hash_h, hash_h2_x, hash_h2_y);

    if (tint_value == zero_value)
    {
        game_state = gamestate::state_menu;
    }

    std::vector<int> car_load{ car1, car2, car3, car4 };
    car_load.push_back(car5);
    for (int car = 0; car < static_cast<int>(car_load.size()); car++)
    {
        draw_image(green_car, car_load[car], green_car_y);
        draw_image(blue_car, car_load[car], blue_car_y);
    }
}