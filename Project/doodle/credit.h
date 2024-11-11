// Filename : credit.h
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/doodle.hpp>

struct Credit_button
{
	double x1{ 0 };
	double x2{ 0 };
	double y1{ 0 };
	double y2{ 0 };
};

class Credit
{
	const doodle::Image credit{ "assets/Credits_Screen.png" };
	const doodle::Image credit_focus{ "assets/Credits_Screen_focus.png" };
	int mouseX{ 0 };
	int mouseY{ 0 };
	bool is_button1{ false };

	Credit_button button1{ -178 ,163,-374,-279 };
	const int zero_x{ 0 };
	const int zero_y{ 0 };
public:
	void draw_credit();
	void credit_mouse_released(doodle::MouseButtons button);
};
inline Credit credit;