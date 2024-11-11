// Filename : credit.cpp
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include "credit.h"
#include "state.h"
#include "sfml-sound.h"

using namespace doodle;
void Credit::draw_credit()
{
	mouseX = get_mouse_x();
	mouseY = get_mouse_y();

	is_button1 = button1.x1 < mouseX && mouseX < button1.x2 && button1.y1 < mouseY && mouseY < button1.y2;
	if (game_state == gamestate::state_credit)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(credit, zero_x, zero_y);
		pop_settings();
	}
	if (is_button1)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(credit_focus, zero_x, zero_y);
		pop_settings();
	}
}
void Credit::credit_mouse_released(doodle::MouseButtons button)
{
	if (button == MouseButtons::Left)
	{
		if (is_button1)
		{
			game_sound.Playsound(static_cast<int>(Sounds::menu));
			game_state = gamestate::state_menu;
			is_button1 = false;
		}
	}
}