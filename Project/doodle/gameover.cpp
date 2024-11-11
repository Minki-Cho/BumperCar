// Filename : gameover.cpp
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include "gameover.h"
#include "state.h"
#include "player.h"
#include "splash_screen.h"
#include "sfml-sound.h"

using namespace doodle;

constexpr int Gameover::Car_calculate(int y, int value1)
{
	return y + value1;
}

void Gameover::draw_gameover()
{
	
	if (game_state == gamestate::state_gameover1)
	{
		default_settings();
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(p1_game_over, zero_value, zero_value);
		pop_settings();
	}
	if (game_state == gamestate::state_gameover2)
	{
		default_settings();
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(p2_game_over, zero_value, zero_value);
		pop_settings();
	}
	if (game_state == gamestate::state_gameover3)
	{
		default_settings();
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(draw_game_over, zero_value, zero_value);
		pop_settings();
	}
	gameover_decoration(Car_calculate(green_y, move_car_val), Car_calculate(blue_y, move_car_val));

	//button click
	mouseX = get_mouse_x();
	mouseY = get_mouse_y();
	
	is_button1 = button1.x1 < mouseX && mouseX < button1.x2 && button1.y1 < mouseY&& mouseY < button1.y2;
	is_button2 = button2.x1 < mouseX && mouseX < button2.x2 && button2.y1 < mouseY&& mouseY < button2.y2;

	if (is_button1)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(play_again, zero_value, zero_value);
		pop_settings();
	}
	if (is_button2)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(exit, zero_value, zero_value);
		pop_settings();
	}
}
void Gameover::gameover_decoration(int green_y1, int blue_y1)
{
	draw_moving_car(movingCarX);
	for ( const int print_greenCar : greenCars)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(green_car, print_greenCar, green_y1);
		pop_settings();
	}
	for ( const int print_blueCar : blueCars)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(blue_car, print_blueCar, blue_y1);
		pop_settings();
	}
}
void Gameover::default_settings()
{
	logo::tint_value = color_max;
	logo::rotate_value = zero_value;
	logo::scale_value = scale_value_min;
}

void Gameover::gameover_mouse_released(doodle::MouseButtons button)
{
	if (button == MouseButtons::Left)
	{
		if (is_button1)
		{
			game_sound.Playsound(static_cast<int>(Sounds::play_again));
			game_state = gamestate::state_menu;
			is_button1 = false;
		}
		if (is_button2)
		{
			game_sound.Playsound(static_cast<int>(Sounds::exit));
			close_window();
			is_button2 = false;
		}
	}
}
