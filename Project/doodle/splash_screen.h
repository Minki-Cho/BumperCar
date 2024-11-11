// Filename : splash_screen.h
// Authors : Yeeun Kim, Minki Cho, Minjae Yu
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <doodle/doodle.hpp>

using namespace doodle;

namespace logo
{ 
	const Image  black_logo{ "assets/DigiPen_BLACK.png" };
	constexpr double black_logo_x{ -550 };
	constexpr double black_logo_y{ 0 };
	const Image  red_logo{ "assets/DigiPen_RED.png" };
	constexpr double red_logo_x{ -550 };
	constexpr double red_logo_y{ 0 };
	const Image green_car{ "assets/green_cars.png" };
	constexpr double green_car_y{ -500 };
	const Image blue_car{ "assets/blue_cars.png" };
	constexpr double blue_car_y{ 400 };
    const Image hash_h{ "assets/hash_h.png" };
    constexpr double hash_h_x{ -500 };
    constexpr double hash_h_y{ 300 };
    const Image hash_a{ "assets/hash_a.png" };
    constexpr double hash_a_x{ -400 };
    constexpr double hash_a_y{ 300 };
    const Image hash_s{ "assets/hash_s.png" };
    constexpr double hash_s_x{ -300 };
    constexpr double hash_s_y{ 300 };
    constexpr double hash_h2_x{ -200 };
    constexpr double hash_h2_y{ 300 };

	constexpr double one_second{ 1 };
	constexpr double two_second{ 1 };
	constexpr double three_second{ 1 };
	constexpr double four_second{ 1 };
	constexpr double rotation_increase_value{ 0.0005 };
	constexpr double scale_increase_value{ 0.005 };

	inline double rotate_value{ 0 };
	inline double scale_value{ 0.5 };
	inline double tint_value{ 250 };

	constexpr int zero_value{ 0 };

	inline double load_time{ 20 };

	constexpr int car1 { -550 };
	constexpr int car2 { -350 };
	constexpr int car3 { -150 };
	constexpr int car4 { 50 };
	constexpr int car5 { 250 };
}
void splash_screen();