// Filename : gameover.h
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/doodle.hpp>
#include <array>
using namespace doodle;

struct Gameover_button
{
	double x1{ 0 };
	double x2{ 0 };
	double y1{ 0 };
	double y2{ 0 };
};
class Gameover
{
	const Image p1_game_over{ "assets/P1_WIN.png" };
	const Image p2_game_over{ "assets/P2_WIN.png" };
	const Image draw_game_over{ "assets/Draw.png"};
	const Image green_car{ "assets/green.png" };
	const Image blue_car{ "assets/blue.png" };
	const Image play_again{ "assets/play_again_focus.png" };
	const Image exit{ "assets/gameover_exit_focus.png" };
	std::array<int, 4> greenCars = { -475,-190,95,375 };
	std::array<int, 4> blueCars = { -336,-50,240,490 };

	const int zero_value{ 0 };
	const int color_max{ 250 };
	const double scale_value_min{ 0.5 };
	const int green_y{ 430 };
	const int blue_y{ 432 };

	Gameover_button button1{ -182 ,165, -260, -160 };
	Gameover_button button2{ -182 ,165, -430, -332 };

	int mouseX{ 0 };
	int mouseY{ 0 };
	bool is_button1{ false };
	bool is_button2{ false };
	int move_car_val{ -50 };
public:
	constexpr int Car_calculate(int y, int value1);
	void draw_gameover();
	void gameover_decoration(int green_y1, int blue_y1);
	void default_settings();
	void gameover_mouse_released(doodle::MouseButtons button);
};
inline Gameover gameover;