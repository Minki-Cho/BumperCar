// Filename : state.cpp
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include <string>
#include "state.h"
#include "main.h"
#include "player.h"
#include "sfml-sound.h"

using namespace doodle;


void Menu::states_main_menu()
{
	push_settings();
	set_image_mode(RectMode::Center);
	draw_image(game_state_img, zero_x, zero_y);
	pop_settings();

	//button click
	mouseX = get_mouse_x();
	mouseY = get_mouse_y();
	is_play_button = play.x1 < mouseX&& mouseX < play.x2&& play.y1 < mouseY&& mouseY < play.y2;
	is_exit_button = exit.x1 < mouseX&& mouseX < exit.x2&& exit.y1 < mouseY&& mouseY < exit.y2;
	is_credit_button = credit.x1 < mouseX&& mouseX < credit.x2&& credit.y1 < mouseY&& mouseY < credit.y2;
	is_how_to_play_button = howtoplay.x1 < mouseX&& mouseX < howtoplay.x2&& howtoplay.y1 < mouseY&& mouseY < howtoplay.y2;

	if (is_exit_button)
	{
		
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(exit_focus, zero_x, zero_y);
		pop_settings();

	}
	else if (is_play_button)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(play_focus, zero_x, zero_y);
		pop_settings();

	}
	else if (is_credit_button)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(credit_focus, zero_x, zero_y);
		pop_settings();
	}
	else if (is_how_to_play_button)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(how_to_focus, zero_x, zero_y);
		pop_settings();
	}
	draw_moving_car(movingCarX);
}

void Menu::menu_mouse_released(doodle::MouseButtons button)
{
	if (button == MouseButtons::Left)
	{
		if (is_exit_button)
		{
			game_sound.Playsound(static_cast<int>(Sounds::exit));
			close_window();
			is_exit_button = false;
		}
		else if (is_play_button)
		{
			game_sound.Playsound(static_cast<int>(Sounds::play));
			game_state = gamestate::state_mapSelection;
			is_play_button = false;
		}
		else if (is_credit_button)
		{
			game_sound.Playsound(static_cast<int>(Sounds::credit));
			game_state = gamestate::state_credit;
			is_credit_button = false;
		}
		else if (is_how_to_play_button)
		{
			game_sound.Playsound(static_cast<int>(Sounds::how_to_play));
			game_state = gamestate::state_how_to_play;
			is_how_to_play_button = false;
		}
	}
}

void draw_moving_car(int& x)
{
	doodle::push_settings();
	doodle::set_rectangle_mode(doodle::RectMode::Center);
	doodle::draw_image(small_car, x, movingCarY);
	doodle::pop_settings();
	x++;
	if (x == x_max_val)
	{
		x = -x_max_val;
	}

	int mouseX = doodle::get_mouse_x();
	int mouseY = doodle::get_mouse_y();
	on_car = x - car_pos < mouseX && mouseX < x + car_pos && movingCarY - car_pos < mouseY && mouseY < movingCarY + car_pos;
	if (on_car)
	{
		doodle::draw_text(abc, x, movingCarY);
	}
}


void car_mouse_released(doodle::MouseButtons button)
{

	if (button == MouseButtons::Left)
	{
		if (on_car)
		{
			game_sound.Playsound(static_cast<int>(Sounds::hash));
		}
	}
}