// Filename : map.cpp
// Authors : Minki Cho, Minjae Yu, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include "map.h"
#include "player.h"
#include "state.h"
#include "sfml-sound.h"

using namespace doodle;
void Map::rectangleMap_draw(int x, int y)
{
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_image_mode(RectMode::Center);
	set_outline_width(outline_width);
	draw_image(shadow, x, y);
	draw_rectangle(map_x, map_y, map_width, map_height); // this is map
	pop_settings();
}

void Map::random_sink_hole()
{
	push_settings();
	no_outline();
	set_fill_color(color_val+ add_color_val, color_val + add_color_val, color_val + add_color_val);
	draw_ellipse(pos_x, pos_y, sink_hole_size);
	set_image_mode(RectMode::Center);
	set_tint_color(color_white-color_val, color_white-color_val);
	
	draw_image(black_hole, pos_x, pos_y);
	pop_settings();

	if (FrameCount % time_limit == zero_time)
	{
		pos_x = doodle::random(random_min, random_max);
		pos_y = doodle::random(random_min, random_max);
		push_settings();
		color_val = color_white;
		set_outline_width(outline_width);
		set_outline_color(color_white, color_black, color_black);
		set_fill_color(color_val, color_val, color_val);
		draw_ellipse(pos_x, pos_y, sink_hole_size);
		pop_settings();
	}
	else
	{
		color_val -= color_decrease;
	}
	sink_hole_collision();
}

void Map::sink_hole_collision()
{
	double p1_dis_x{ p.get_player1_pos().x - pos_x };
	double p1_dis_y{ p.get_player1_pos().y - pos_y };
	double p1_distance = sqrt(p1_dis_x * p1_dis_x + p1_dis_y * p1_dis_y);
	double p2_dis_x{ p.get_player2_pos().x - pos_x };
	double p2_dis_y{ p.get_player2_pos().y - pos_y };
	double p2_distance = sqrt(p2_dis_x * p2_dis_x + p2_dis_y * p2_dis_y);

	if (color_val <= color_black)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(black_hole, pos_x, pos_y);
		pop_settings();

		if (p1_distance < collision_val)
		{
			is_player1_lose = true;
			vibebration = p.shaking.default_val;
			if (FrameCount % set_frame60 == zero_time)
			{
				game_state = gamestate::state_gameover2;
				make_defalt();
			}
		}
		else
		{
			is_player1_lose = false;
		}
		if (p2_distance < collision_val)
		{
			is_player2_lose = true;
			vibebration = p.shaking.default_val;
			if (FrameCount % set_frame60 == zero_time)
			{
				game_state = gamestate::state_gameover1;
				make_defalt();
			}
		}
		else
		{
			is_player2_lose = false;
		}
		if (is_player1_lose == true && is_player2_lose)
		{
			vibebration = p.shaking.default_val;
			if (FrameCount % set_frame60 == zero_time)
			{
				game_state = gamestate::state_gameover3;
				make_defalt();
			}
		}
	}
}
void Map::set_color_val(int val)
{
	color_val = val;
}

void Map::doughnutMap_draw()
{
	push_settings();
	set_image_mode(RectMode::Center);
	draw_image(doughnut_img, doughnut.x, doughnut.y);
	set_fill_color(inside);
	no_outline();
	draw_ellipse(inside_x, inside_y, inside_size);
	pop_settings();
}

void Map::doughnutMap_collision()
{
	
	vec2 player1_vector{ zero_vector,zero_vector };
	vec2 player2_vector{ zero_vector,zero_vector };
	player1_vector = p.get_player1_pos();
	player2_vector = p.get_player2_pos();

	double p1_with_x{ player1_vector.x - doughnut.x };
	double p1_with_y{ player1_vector.y - doughnut.y };
	double p2_with_x{ player2_vector.x - doughnut.x };
	double p2_with_y{ player2_vector.y - doughnut.y };

	double p1_map_dis{ sqrt(p1_with_x * p1_with_x + p1_with_y * p1_with_y) };
	double p2_map_dis{ sqrt(p2_with_x * p2_with_x + p2_with_y * p2_with_y) };

	if (p1_map_dis > collision_dis1 || p1_map_dis < collision_dis2)
	{
		vibebration = p.shaking.default_val;
		is_player1_lose = true;
		if (FrameCount % set_frame50 == zero_time)
		{
			game_sound.Playsound(static_cast<int>(Sounds::car_out));
			game_state = gamestate::state_gameover2;
			make_defalt();
		}
	}
	else
	{
		is_player1_lose = false;
	}
	if (p2_map_dis > collision_dis1 || p2_map_dis < collision_dis2)
	{
		vibebration = p.shaking.default_val;
		is_player2_lose = true;
		if (FrameCount % set_frame50 == zero_time)
		{
			game_sound.Playsound(static_cast<int>(Sounds::car_out));
			game_state = gamestate::state_gameover1;
			make_defalt();
		}
		
	}
	else
	{
		is_player2_lose = false;
	}

}

void Map::make_defalt()
{
	p.velocity.p1.x = p.velocity.zero;
	p.velocity.p1.y = p.velocity.zero;
	p.velocity.p2.x = p.velocity.zero;
	p.velocity.p2.y = p.velocity.zero;
	p.pos.player1.x = p.pos.player1_pos_x;
	p.pos.player1.y = p.pos.player1_pos_y;
	p.pos.player2.x = p.pos.player2_pos_x;
	p.pos.player2.y = p.pos.player2_pos_y;
	color_val = color_white;
}