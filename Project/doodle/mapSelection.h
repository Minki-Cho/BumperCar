// Filename : mapSelection.h
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/image.hpp>

struct Matrix
{
	double x1{ 0 };
	double x2{ 0 };
	double y1{ 0 };
	double y2{ 0 };
};

class MapSelection
{
	const doodle::Image map_selection{ "assets/Map_Screen.png" };
	const doodle::Image map1_focus{ "assets/Map1.png" };
	const doodle::Image map2_focus{ "assets/Map2.png" };
	const doodle::Image map3_focus{ "assets/Map3.png" };
	const doodle::Image map4_focus{ "assets/Map4.png" };
	int pos_x{ 0 };
	int pos_y{ 0 };
	Matrix button1{ -458,-64,0,381 };
	Matrix button2{ 50,446,0,381 };
	Matrix button3{ -458,-64,-445, -63 };
	Matrix button4{ 50,446,-445, -63 };
	int mouseX{ 0 };
	int mouseY{ 0 };
	bool is_button1{ false };
	bool is_button2{ false };
	bool is_button3{ false };
	bool is_button4{ false };
public:
	void draw_map_selection();
	void mapselection_mouse_released(doodle::MouseButtons button);
	void default_settings();
};
inline MapSelection mapSelection;
