// Filename : howtoplay.h
// Authors : Yeeun Kim, Minjae Yu, Minki Cho
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.
#pragma once
#include <doodle/doodle.hpp>

struct Howto_button
{
	double x1{ 0 };
	double x2{ 0 };
	double y1{ 0 };
	double y2{ 0 };
};

class Howto
{
private:
	const doodle::Image howto{ "assets/HowToPlay.png" };
	const doodle::Image howto_focus{ "assets/HowToPlay_focus.png" };
	int mouseX{ 0 };
	int mouseY{ 0 };
	bool is_button1{ false };

	Howto_button button1{ -175 ,175,-455,-355 };
	const int zero_x{ 0 };
	const int zero_y{ 0 };
public:
	void draw_howto();
	void howto_mouse_released(doodle::MouseButtons button);
};
inline Howto ht;