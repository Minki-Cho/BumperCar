// Filename : mapSelection.cpp
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include "mapSelection.h"
#include "state.h"
#include "map.h"
#include "player.h"
#include "sfml-sound.h"

using namespace doodle;
void MapSelection::draw_map_selection()
{
	push_settings();
	set_image_mode(RectMode::Center);
	draw_image(map_selection, pos_x, pos_y);
	pop_settings();

	mouseX = get_mouse_x();
	mouseY = get_mouse_y();

	is_button1 = button1.x1 < mouseX && mouseX < button1.x2 && button1.y1 < mouseY && mouseY < button1.y2;
	is_button2 = button2.x1 < mouseX && mouseX < button2.x2 && button2.y1 < mouseY && mouseY < button2.y2;
	is_button3 = button3.x1 < mouseX && mouseX < button3.x2 && button3.y1 < mouseY && mouseY < button3.y2;
	is_button4 = button4.x1 < mouseX && mouseX < button4.x2 && button4.y1 < mouseY && mouseY < button4.y2;

	if (is_button1)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(map1_focus, 0, 0);
		pop_settings();
	}
	if (is_button2)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(map2_focus, 0, 0);
		pop_settings();
	}
	if (is_button3)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(map3_focus, 0, 0);
		pop_settings();
	}
	if (is_button4)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(map4_focus, 0, 0);
		pop_settings();
	}
}

void MapSelection::default_settings()
{
	map.set_color_val(255);
	pb.p1_item_time = false;
	pb.p2_item_time = false;

	pb.p1_item2_time = false;
	pb.p2_item2_time = false;
}

void MapSelection::mapselection_mouse_released(doodle::MouseButtons button)
{
	if (button == MouseButtons::Left)
	{
		if (is_button1)
		{
			game_sound.Playsound(static_cast<int>(Sounds::select));
			default_settings();
			game_state = gamestate::state_map1;
			is_button1 = false;
		}
		else if (is_button2)
		{
			game_sound.Playsound(static_cast<int>(Sounds::select));
			default_settings();
			game_state = gamestate::state_map2;
			is_button2 = false;
		}
		else if (is_button3)
		{
			game_sound.Playsound(static_cast<int>(Sounds::select));
			default_settings();
			game_state = gamestate::state_map3;
			is_button3 = false;
		}
		else if (is_button4)
		{
			game_sound.Playsound(static_cast<int>(Sounds::select));
			default_settings();
			game_state = gamestate::state_map4;
			is_button4 = false;
		}
	}
}

