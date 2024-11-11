// Filename : player.cpp
// Authors : Minjae Yu, Minki Cho, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include "player.h"
#include "item.h"
#include "state.h"
#include "map.h"
#include "sfml-sound.h"
void Player::draw_player()
{
	
	push_settings();
	set_image_mode(RectMode::Center);
	screen_effect();
	apply_translate(pos.player1.x, pos.player1.y);
	apply_rotate(player1_angle);
	//good item
	if (pb.p1_item_time == true)
	{
		if (is_player1_lose)
		{
			set_tint_color(player_transparent, player_transparent);
		}
		else
		{
			set_tint_color(player_tint, player_tint);
		}
		draw_image(img.big_car1, img.img_pos.x, img.img_pos.y);

	}
	//bad item
	else if (pb.p1_item2_time == true)
	{
		if (is_player1_lose)
		{
			set_tint_color(player_transparent, player_transparent);
		}
		else
		{
			set_tint_color(player_tint, player_tint);
		}
		draw_image(img.small_car1, img.img_pos.x, img.img_pos.y);
	}
	else
	{
		if (is_player1_lose)
		{
			set_tint_color(player_transparent, player_transparent);
		}
		else
		{
			set_tint_color(player_tint, player_tint);
		}
		draw_image(img.car1, img.img_pos.x, img.img_pos.y);
	}
	pop_settings();

	push_settings();
	set_image_mode(RectMode::Center);
	screen_effect();
	apply_translate(pos.player2.x, pos.player2.y);
	apply_rotate(player2_angle);
	//good item
	if (pb.p2_item_time == true)
	{
		if (is_player2_lose)
		{
			set_tint_color(player_transparent, player_transparent);
		}
		else
		{
			set_tint_color(player_tint, player_tint);
		}
		draw_image(img.big_car2, img.img_pos.x, img.img_pos.y);
	}
	//bad item
	else if (pb.p2_item2_time == true)
	{
		if (is_player2_lose)
		{
			set_tint_color(player_transparent, player_transparent);
		}
		else
		{
			set_tint_color(player_tint, player_tint);
		}
		draw_image(img.small_car2, img.img_pos.x, img.img_pos.y);
	}
	//else
	else
	{
		if (is_player2_lose)
		{
			set_tint_color(player_transparent, player_transparent);
		}
		else
		{
			set_tint_color(player_tint, player_tint);
		}
		draw_image(img.car2, img.img_pos.x, img.img_pos.y);
	}
	pop_settings();
}

void Player::keyboard_pressed(doodle::KeyboardButtons button)
{

	// player 1
	if (button == KeyboardButtons::W)
	{
		pb.p1_front = true;
	}
	else if (button == KeyboardButtons::S)
	{
		pb.p1_back = true;
	}
	else if (button == KeyboardButtons::A)
	{
		pb.p1_left = true;
	}
	else if (button == KeyboardButtons::D)
	{
		pb.p1_right = true;
	}

	// player 2
	if (button == KeyboardButtons::Up)
	{
		pb.p2_front = true;
	}
	else if (button == KeyboardButtons::Down)
	{
		pb.p2_back = true;
	}
	else if (button == KeyboardButtons::Left)
	{
		pb.p2_left = true;
	}
	else if (button == KeyboardButtons::Right)
	{
		pb.p2_right = true;
	}

}

void Player::keyboard_released(doodle::KeyboardButtons button)
{

	// player 1
	if (button == KeyboardButtons::W)
	{
		pb.p1_front = false;
	}
	else if (button == KeyboardButtons::S)
	{
		pb.p1_back = false;
	}
	else if (button == KeyboardButtons::A)
	{
		pb.p1_left = false;
	}
	else if (button == KeyboardButtons::D)
	{
		pb.p1_right = false;
	}

	// player 2
	if (button == KeyboardButtons::Up)
	{
		pb.p2_front = false;
	}
	else if (button == KeyboardButtons::Down)
	{
		pb.p2_back = false;
	}
	else if (button == KeyboardButtons::Left)
	{
		pb.p2_left = false;
	}
	else if (button == KeyboardButtons::Right)
	{
		pb.p2_right = false;
	}

}

void Player::player_movement()
{
	//player 1
	pos.player1.x += velocity.p1.x;
	pos.player1.y += velocity.p1.y;
	velocity.p1.x += acceleration.p1.x;
	velocity.p1.y += acceleration.p1.y;

	if (pb.p1_front)
	{
		draw_light(pos.player1.x, pos.player1.y, player1_angle, pb.p1_item_time, pb.p1_item2_time);
		acceleration.p1.x = cos(player1_angle) * DeltaTime * acceleration.increase_val;
		acceleration.p1.y = sin(player1_angle) * DeltaTime * acceleration.increase_val;
	}
	if (pb.p1_back)
	{
		acceleration.p1.x = cos(player1_angle) * DeltaTime * acceleration.decrease_val;
		acceleration.p1.y = sin(player1_angle) * DeltaTime * acceleration.decrease_val;
	}
	if (!pb.p1_front && !pb.p1_back)
	{
		acceleration.p1.x = acceleration.zero;
		acceleration.p1.y = acceleration.zero;

		if (velocity.p1.x > velocity.zero)
		{
			velocity.p1.x -= DeltaTime * velocity.value;
		}
		else if (velocity.p1.x < velocity.zero)
		{
			velocity.p1.x += DeltaTime * velocity.value;
		}

		if (velocity.p1.y > velocity.zero)
		{
			velocity.p1.y -= DeltaTime * velocity.value;
		}
		else if (velocity.p1.y < velocity.zero)
		{
			velocity.p1.y += DeltaTime * velocity.value;
		}
	}
	if (pb.p1_left)
	{
		player1_angle += DeltaTime * rotate_value;
	}
	else if (pb.p1_right)
	{
		player1_angle -= DeltaTime * rotate_value;
	}

	//player 2
	pos.player2.x += velocity.p2.x;
	pos.player2.y += velocity.p2.y;
	velocity.p2.x += acceleration.p2.x;
	velocity.p2.y += acceleration.p2.y;

	if (pb.p2_front)
	{
		draw_light(pos.player2.x, pos.player2.y, player2_angle, pb.p2_item_time, pb.p2_item2_time);
		acceleration.p2.x = cos(player2_angle) * DeltaTime * acceleration.increase_val;
		acceleration.p2.y = sin(player2_angle) * DeltaTime * acceleration.increase_val;
	}
	if (pb.p2_back)
	{
		acceleration.p2.x = cos(player2_angle) * DeltaTime * acceleration.decrease_val;
		acceleration.p2.y = sin(player2_angle) * DeltaTime * acceleration.decrease_val;
	}
	if (!pb.p2_front && !pb.p2_back)
	{
		acceleration.p2.x = acceleration.zero;
		acceleration.p2.y = acceleration.zero;

		if (velocity.p2.x > velocity.zero)
		{
			velocity.p2.x -= DeltaTime * velocity.value;
		}
		else if (velocity.p2.x < velocity.zero)
		{
			velocity.p2.x += DeltaTime * velocity.value;
		}

		if (velocity.p2.y > velocity.zero)
		{
			velocity.p2.y -= DeltaTime * velocity.value;
		}
		else if (velocity.p2.y < velocity.zero)
		{
			velocity.p2.y += DeltaTime * velocity.value;
		}
	}
	if (pb.p2_left)
	{
		player2_angle += DeltaTime * rotate_value;
	}
	else if (pb.p2_right)
	{
		player2_angle -= DeltaTime * rotate_value;
	}
}

void Player::player_collision()
{
	double player_dis_x{ pos.player1.x - pos.player2.x };
	double player_dis_y{ pos.player1.y - pos.player2.y };
	double player_distance = sqrt(player_dis_x * player_dis_x + player_dis_y * player_dis_y);

	double p1_velocity_length = sqrt(velocity.p1.x * velocity.p1.x + velocity.p1.y * velocity.p1.y);
	double p2_velocity_length = sqrt(velocity.p2.x * velocity.p2.x + velocity.p2.y * velocity.p2.y);

	double distance_value{ (player1_size + player2_size) / 2 };

	//player1_size == player2_size
	if (player_distance <= distance_value)
	{
		game_sound.Playsound(static_cast<int>(Sounds::bump));
		if (player1_size == player2_size)
		{
			pb.is_collide = true;
			pb.velocity_calculate = true;
			//player 1
			if (p1_velocity_length > p2_velocity_length)
			{
				if (pb.velocity_calculate)
				{
					velocity.p1_collision = velocity.p1;
					calculate_angle = atan2(velocity.p1_collision.y, velocity.p1_collision.x);

					velocity.p1.x = velocity.zero;
					velocity.p1.y = velocity.zero;
					velocity.p2.x = velocity.zero;
					velocity.p2.y = velocity.zero;

					pb.velocity_calculate = false;
				}
				pos.player2.x += DeltaTime * velocity.teleport_val * cos(calculate_angle);
				pos.player2.y += DeltaTime * velocity.teleport_val * sin(calculate_angle);
				velocity.p2.x += velocity.p1_collision.x * DeltaTime * velocity.p_far;
				velocity.p2.y += velocity.p1_collision.y * DeltaTime * velocity.p_far;

				velocity.p1.x += velocity.p1_collision.x * DeltaTime * velocity.close;
				velocity.p1.y += velocity.p1_collision.y * DeltaTime * velocity.close;
			}
			//player 2
			else if (p1_velocity_length < p2_velocity_length)
			{
				

				if (pb.velocity_calculate)
				{
					velocity.p2_collision = velocity.p2;
					calculate_angle = atan2(velocity.p2_collision.y, velocity.p2_collision.x);

					velocity.p1.x = velocity.zero;
					velocity.p1.y = velocity.zero;
					velocity.p2.x = velocity.zero;
					velocity.p2.y = velocity.zero;

					pb.velocity_calculate = false;
				}
				pos.player1.x += DeltaTime * velocity.teleport_val * cos(calculate_angle);
				pos.player1.y += DeltaTime * velocity.teleport_val * sin(calculate_angle);
				velocity.p1.x += velocity.p2_collision.x * DeltaTime * velocity.p_far;
				velocity.p1.y += velocity.p2_collision.y * DeltaTime * velocity.p_far;

				velocity.p2.x += velocity.p2_collision.x * DeltaTime * velocity.close;
				velocity.p2.y += velocity.p2_collision.y * DeltaTime * velocity.close;
			}
		}
	}
	else
	{
		pb.is_collide = false;
	}

	//collision by player size
	if (player_distance <= distance_value)
	{
		pb.is_collide = true;
		pb.velocity_calculate = true;
		//player 1
		if (player1_size > player2_size)
		{
			//p1 speed > p2_speed
			if (p1_velocity_length > p2_velocity_length)
			{
				if (pb.velocity_calculate)
				{
					velocity.p1_collision = velocity.p1;
					calculate_angle = atan2(velocity.p1_collision.y, velocity.p1_collision.x);

					velocity.p1.x = velocity.zero;
					velocity.p1.y = velocity.zero;
					velocity.p2.x = velocity.zero;
					velocity.p2.y = velocity.zero;

					pb.velocity_calculate = false;
				}
				pos.player2.x += DeltaTime * velocity.teleport_val * cos(calculate_angle);
				pos.player2.y += DeltaTime * velocity.teleport_val * sin(calculate_angle);
				velocity.p2.x += velocity.p1_collision.x * DeltaTime * velocity.p_far;
				velocity.p2.y += velocity.p1_collision.y * DeltaTime * velocity.p_far;
			}
			//p1_speed < p2_speed
			else if (p1_velocity_length < p2_velocity_length)
			{
				if (pb.velocity_calculate)
				{
					velocity.p2_collision = velocity.p2;
					calculate_angle = atan2(velocity.p2_collision.y, velocity.p2_collision.x);

					velocity.p1.x = velocity.zero;
					velocity.p1.y = velocity.zero;
					velocity.p2.x = velocity.zero;
					velocity.p2.y = velocity.zero;

					pb.velocity_calculate = false;
				}
				pos.player2.x += DeltaTime * -velocity.teleport_val * cos(calculate_angle);
				pos.player2.y += DeltaTime * -velocity.teleport_val * sin(calculate_angle);
				velocity.p2.x += velocity.p2_collision.x * DeltaTime * -velocity.p_far;
				velocity.p2.y += velocity.p2_collision.y * DeltaTime * -velocity.p_far;
			}
		}
		//player 2
		else if (player1_size < player2_size)
		{
			//p1_speed > p2_speed
			if (p1_velocity_length > p2_velocity_length)
			{
				if (pb.velocity_calculate)
				{
					velocity.p1_collision = velocity.p1;
					calculate_angle = atan2(velocity.p1_collision.y, velocity.p1_collision.x);

					velocity.p1.x = velocity.zero;
					velocity.p1.y = velocity.zero;
					velocity.p2.x = velocity.zero;
					velocity.p2.y = velocity.zero;

					pb.velocity_calculate = false;
				}
				pos.player1.x += DeltaTime * -velocity.teleport_val * cos(calculate_angle);
				pos.player1.y += DeltaTime * -velocity.teleport_val * sin(calculate_angle);
				velocity.p1.x += velocity.p1_collision.x * DeltaTime * -velocity.p_far;
				velocity.p1.y += velocity.p1_collision.y * DeltaTime * -velocity.p_far;
			}
			else if (p1_velocity_length < p2_velocity_length)
			{
				if (pb.velocity_calculate)
				{
					velocity.p2_collision = velocity.p2;
					calculate_angle = atan2(velocity.p2_collision.y, velocity.p2_collision.x);

					velocity.p1.x = velocity.zero;
					velocity.p1.y = velocity.zero;
					velocity.p2.x = velocity.zero;
					velocity.p2.y = velocity.zero;

					pb.velocity_calculate = false;
				}
				pos.player1.x += DeltaTime * velocity.teleport_val * cos(calculate_angle);
				pos.player1.y += DeltaTime * velocity.teleport_val * sin(calculate_angle);
				velocity.p1.x += velocity.p2_collision.x * DeltaTime * velocity.p_far;
				velocity.p1.y += velocity.p2_collision.y * DeltaTime * velocity.p_far;
			}
		}
	}
	else
	{
		pb.is_collide = false;
	}
}

void Player::map_player_collision()
{
	if (pos.player1.x < map_limit.x1 || pos.player1.x > map_limit.x2 || pos.player1.y < map_limit.y1 || pos.player1.y > map_limit.y2)
	{
		vibebration = shaking.default_val;
		pb.p1_item = false;
		pb.p2_item = false;
		pb.p1_item_time = false;
		pb.p2_item_time = false;
		is_player1_lose = true;
		
		if (FrameCount % gameover_count == 0)
		{
			game_sound.Playsound(static_cast<int>(Sounds::car_out));
			game_state = gamestate::state_gameover2;
			velocity.p1.x = velocity.zero;
			velocity.p1.y = velocity.zero;
			velocity.p2.x = velocity.zero;
			velocity.p2.y = velocity.zero;
			pos.player1.x = pos.player1_pos_x;
			pos.player1.y = pos.player1_pos_y;
			pos.player2.x = pos.player2_pos_x;
			pos.player2.y = pos.player2_pos_y;
			p.player1_size = player_normal_size;
			p.player2_size = player_normal_size;
		}
	}
	else
	{
		is_player1_lose = false;
	}
	if (pos.player2.x < map_limit.x1 || pos.player2.x > map_limit.x2 || pos.player2.y < map_limit.y1 || pos.player2.y > map_limit.y2)
	{
		vibebration = shaking.default_val;
		pb.p1_item = false;
		pb.p2_item = false;
		pb.p1_item_time = false;
		pb.p2_item_time = false;
		is_player2_lose = true;
		if (FrameCount % gameover_count == 0)
		{
			game_sound.Playsound(static_cast<int>(Sounds::car_out));
			game_state = gamestate::state_gameover1;
			velocity.p1.x = velocity.zero;
			velocity.p1.y = velocity.zero;
			velocity.p2.x = velocity.zero;
			velocity.p2.y = velocity.zero;
			pos.player1.x = pos.player1_pos_x;
			pos.player1.y = pos.player1_pos_y;
			pos.player2.x = pos.player2_pos_x;
			pos.player2.y = pos.player2_pos_y;
			p.player1_size = player_normal_size;
			p.player2_size = player_normal_size;
		}
		
	}
	else
	{
		is_player2_lose = false;
	}
}

void Player::screen_effect()
{
	const double shake = vibebration * vibebration;
	const double offsetX = MaxOffset * shake * random(shaking.min, shaking.max);
	const double offsetY = MaxOffset * shake * random(shaking.min, shaking.max);
	const double angle = MaxAngle * shake * random(shaking.min, shaking.max);
	apply_translate(offsetX, offsetY);
	apply_rotate(angle);
	vibebration -= doodle::DeltaTime;
	vibebration = std::clamp(vibebration, shaking.zero, shaking.max);
}

vec2 Player::get_player1_pos()
{
	vec2 p1_pos{ pos.player1.x,pos.player1.y };
	return p1_pos;
}

vec2 Player::get_player2_pos()
{
	vec2 p2_pos{ pos.player2.x,pos.player2.y };
	return p2_pos;
}

double Player::get_player1_size()
{
	return player1_size;
}

double Player::get_player2_size()
{
	return player2_size;
}

void Player::set_player1_size(double size)
{
	player1_size = size;
}

void Player::set_player2_size(double size)
{
	player2_size = size;
}

void Player::draw_light(double x, double y, double rotate, bool postive_item, bool negative_item)
{
	push_settings();
	set_image_mode(RectMode::Center);
	apply_translate(x, y);
	apply_rotate(rotate);
	if (postive_item) { apply_scale(light.big_scale); }
	else if (negative_item) { apply_scale(light.small_scale); }
	else { apply_scale(light.normal_scale); }
	set_tint_color(light.tint_value, light.tint_value);
	draw_image(img.car_light, light.pos_light.x, light.pos_light.y);
	pop_settings();
}