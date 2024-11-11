// Filename : state.h
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/doodle.hpp>

enum class gamestate
{
	state_logo, state_menu, state_mapSelection, state_map1, state_map2, state_map3, state_map4, state_gameover1, state_gameover2, state_gameover3, state_credit, state_how_to_play
};
inline gamestate game_state{ gamestate::state_logo };

struct Menu_button
{
	double x1{ 0 };
	double x2{ 0 };
	double y1{ 0 };
	double y2{ 0 };
};
class Menu
{
	const doodle::Image game_state_img{"assets/First_Screen.png"};
	const doodle::Image play_focus{ "assets/play_focus.png" };
	const doodle::Image exit_focus{ "assets/exit_focus.png" };
	const doodle::Image credit_focus{ "assets/credit_focus.png" };
	const doodle::Image how_to_focus{ "assets/HowTo_focus.png" };

	Menu_button play{ -169 ,176, -113, -20 };
	Menu_button exit{ -169 ,176,-265, -171 };
	Menu_button credit{ -169 ,176, -416, -324 };
	Menu_button howtoplay{ 410,505,-475,-380 };

	int mouseX{ 0 };
	int mouseY{ 0 };

	bool is_play_button{ false };
	bool is_exit_button{ false };
	bool is_credit_button{ false };
	bool is_how_to_play_button{ false };

	const int zero_x{ 0 };
	const int zero_y{ 0 };
public:
	void states_main_menu();
	void menu_mouse_released(doodle::MouseButtons button);
};
inline Menu menu;
inline int movingCarX{ -500 };

const doodle::Image small_car{ "assets/small_car.png" };
constexpr int x_max_val{ 500 };
constexpr int movingCarY{ -480 };
constexpr int car_pos{ 50 };
void draw_moving_car(int& x);
inline bool on_car{ false };
void car_mouse_released(doodle::MouseButtons button);